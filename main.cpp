#include "main.h"

typedef std::numeric_limits<int> int_lim;

int main() {
    Timer t;
    t.initialize_watch(1);
    t.initialize_watch(2);

    Process_settings settings{};

    srand(time(nullptr));

    int choice = CLInputs::numInput(
        "Pasirinkte duomenu generavimo metoda (1 - Ranka, 2 - Generuoti pazymius, 3 - Generuoti ir pazymius ir studentu vardus, pavardes, 4 - Skaityti is failo, 5 - Generuoti faila, 6 - Baigti darba): ",
        6, 1);

    switch (choice) {
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

    if (settings.generate_input_file) {
        int student_num = CLInputs::numInput("Iveskite sugeneruoto failo studentu skaiciu: ", int_lim::max(), 1);
        int hw_num = CLInputs::numInput("Iveskite sugeneruot failo namu darbu skaiciu: ", int_lim::max(), 1);
        std::string file_name = CLInputs::strInput("Iveskite sugeneruoto failo pavadinima: ");

        t.start_watch(1);
        FileGen::gen_file(student_num, hw_num, file_name);
        t.stop_watch(1, "Failo sukurimo laikas:");
        cout << "Baigtas failo kurimas\n";
        t.write_to_file("file-gen.txt");
        return 0;
    }

    if (settings.get_students_from_file) {
        settings.input_file_name = CLInputs::strInput("Iveskite nuskaitomo failo pavadinima: ");
    }

    settings.sort_method = CLInputs::numInput(
"Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ",
5, 1);
    settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) ==
                              2;
    t.start_watch(2);

    std::vector<Student> students;

    t.start_watch(1);
    if (settings.get_students_from_file) {
        File_students file(settings.input_file_name);
        file.read_students(students);
    } else {
        students = CL_Students::get_user_input(settings.generate_names, settings.generate_grades);
    }
    t.stop_watch(1, "Duomenu nuskaitymas:");

    t.start_watch(1);
    Calc_Students::calc_grades(students);
    t.stop_watch(1, "Duomenu apskaiciavimas:");
    t.start_watch(1);
    Calc_Students::sort_students(students, settings.sort_method);
    t.stop_watch(1, "Duomenu surusiavimas:");

    t.start_watch(1);
    std::vector<Student> high_st;
    std::vector<Student> low_st;

    for (auto student: students) {
        if (student.final_score_avg < 5.0) {
            low_st.push_back(student);
        } else {
            high_st.push_back(student);
        }
    }
    t.stop_watch(1, "Studentu iskirstymas i dvi grupes:");


    Output_students output;

    t.start_watch(1);
    output.open_file("out.txt");
    output.output_students(students, settings.output_to_file);
    output.close_file();
    t.stop_watch(1, "Bendras isvedimas:");
    students.clear();

    t.start_watch(1);
    output.open_file("nuskriaustukai.txt");
    output.output_students(low_st, true);
    output.close_file();
    low_st.clear();

    output.open_file("galvociai.txt");
    output.output_students(high_st, true);
    output.close_file();
    t.stop_watch(1, "Bendras isvedimas:");
    high_st.clear();

    t.stop_watch(2, "Programos veikimo laikas:");

    t.write_to_file("laikai.txt");
    return 0;
}
