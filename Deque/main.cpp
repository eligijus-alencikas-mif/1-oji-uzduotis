#include "main.h"

typedef std::numeric_limits<int> int_lim;

int main()
{
    Timer t;
    std::string watch_name = "Skirstymas";
    t.initialize_watch(1, watch_name);

    Process_settings settings{};

    srand(time(nullptr));

    int choice = CLInputs::numInput(
        "Pasirinkte duomenu generavimo metoda (1 - Ranka, 2 - Generuoti pazymius, 3 - Generuoti ir pazymius ir studentu vardus, pavardes, 4 - Skaityti is failo, 5 - Generuoti faila, 6 - Baigti darba): ",
        6, 1);

    switch (choice)
    {
    case 1:
        settings.generate_names = false;
        settings.generate_grades = false;
        settings.get_students_from_file = false;
        break;
    case 2:
        settings.generate_grades = true;
        break;
    case 3:
        settings.generate_names = true;
        settings.generate_grades = true;
        break;
    case 4:
        settings.get_students_from_file = true;
        break;
    case 5:
        settings.generate_input_file = true;
        break;
    default:
        return 0;
    }

    if (settings.generate_input_file)
    {
        int student_num = CLInputs::numInput("Iveskite sugeneruoto failo studentu skaiciu: ", int_lim::max(), 1);
        int hw_num = CLInputs::numInput("Iveskite sugeneruot failo namu darbu skaiciu: ", int_lim::max(), 1);
        std::string file_name = CLInputs::strInput("Iveskite sugeneruoto failo pavadinima: ");

        FileGen::gen_file(student_num, hw_num, file_name);
        cout << "Baigtas failo kurimas\n";
        return 0;
    }

    if (settings.get_students_from_file)
    {
        settings.input_file_name = CLInputs::strInput("Iveskite nuskaitomo failo pavadinima: ");
    }

    std::deque<Student> students;

    if (settings.get_students_from_file)
    {
        File_students file(settings.input_file_name);
        file.read_students(students);

        if (!file.file_opened)
            return 0;

        settings.sort_method = CLInputs::numInput(
            "Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ",
            5, 1);
        settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) ==
                                  2;
    }
    else
    {

        settings.sort_method = CLInputs::numInput(
            "Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ",
            5, 1);
        settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) ==
                                  2;

        students = CL_Students::get_user_input(
            settings.generate_names,
            settings.generate_grades);
    }
    Calc_Students::calc_grades(students);
    t.start_watch(2);
    Calc_Students::sort_students(students, settings.sort_method);
    t.pause_watch(2);

    // std::deque<Student> high_st;
    std::deque<Student> low_st;

    Output_students output;

    if (settings.output_to_file)
        output.open_file("out.txt");
    output.output_students(students, settings.output_to_file);
    if (settings.output_to_file)
        output.close_file();

    t.start_watch(1);

    auto size = students.size();
    for (size_t i = 0; i < size; i++)
    {
        if (students.front().final_score_avg < 5.0)
        {
            low_st.push_back(students.front());
        }
        else
        {
            students.push_back(students.front());
        }
        students.pop_front();
    }

    // auto end = students.end();
    // for (auto it = students.begin(); it != end;)
    // {
    //     if (it->final_score_avg < 5.0)
    //     {
    //         low_st.push_back(*it);
    //         // it = students.erase(it);
    //     }
    //     else
    //     {
    //         students.push_back(*it);
    //         students.pop_front();
    //         ++it;
    //     }
    // }

    // for (auto student : students)
    // {
    //     if (student.final_score_avg < 5.0)
    //     {
    //         low_st.push_back(student);
    //     }
    //     else
    //     {
    //         students.push_back(student);
    //         students.pop_front();
    //         // high_st.push_back(student);
    //     }
    // }
    t.pause_watch(1);

    output.open_file("nuskriaustukai.txt");
    output.output_students(low_st, true);
    output.close_file();
    low_st.clear();

    output.open_file("galvociai.txt");
    output.output_students(students, true);
    output.close_file();
    students.clear();

    t.write_times("laikai.txt");
    return 0;
}
