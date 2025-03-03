#include "main.h"

typedef std::numeric_limits<int> int_lim;

int main() {
    Timer t;
    t.initialize_watch(1);
    t.initialize_watch(2);

    Process_settings settings{};

    srand(time(nullptr));

    int choice = CLInputs::numInput(
        "Pasirinkte duomenu generavimo metoda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - skaityti is sugenruoto failo, 6 - baigti darba): ",
        6, 1);

    switch (choice) {
        case 1:
            settings.generate_names = false;
            settings.generate_grades = false;
            settings.get_students_from_file = false;
            break;
        case 2:
            settings.generate_names = true;
            break;
        case 3:
            settings.generate_names = true;
            settings.generate_grades = true;
            break;
        case 4:
            settings.get_students_from_file = true;
            break;
        case 5:
            settings.get_students_from_file = true;
            settings.generate_input_file = true;
            break;
        default:
            return 0;
    }

    settings.sort_method = CLInputs::numInput(
        "Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ",
        5, 1);
    settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) ==
                              2;

    t.start_watch(2);
    t.start_watch(1);

    if (settings.generate_input_file) {
        t.pause_watch(1);
        t.pause_watch(2);
        int student_num = CLInputs::numInput("Iveskite sugeneruoto failo studentu skaiciu: ", int_lim::max(), 1);
        int hw_num = CLInputs::numInput("Iveskite sugeneruot failo namu darbu skaiciu: ", int_lim::max(), 1);
        t.start_watch(2);
        t.start_watch(1);
        FileGen::gen_file(student_num, hw_num);
        t.stop_watch(1, "Failo sukurimo laikas:");
    }


    std::vector<Student> students;

    t.start_watch(1);
    if (settings.get_students_from_file) {
        File_students file;
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

    // t.start_watch(1);
    // output.open_file("out.txt");
    // output.output_students(students, settings.output_to_file);
    // output.close_file();
    // t.stop_watch(1, "Bendras isvedimas:");
    // students.clear();

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
