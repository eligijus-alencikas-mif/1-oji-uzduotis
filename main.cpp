#include "main.h"
#include "file_gen.h"
#include "inputs.h"

int main() {
    srand(time(nullptr));

    int choice = CLInputs::numInput("Pasirinkte duomenu generavimo metoda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - skaityti is sugenruoto failo, 6 - baigti darba): ", 6, 1);

    Process_settings settings{};

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

    settings.sort_method = CLInputs::numInput("Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ", 5, 1);
    settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) == 2;

    if (settings.generate_input_file) {
        int student_num = CLInputs::numInput("Iveskite sugeneruoto failo studentu skaiciu: ", INT_MAX, 1);
        int hw_num = CLInputs::numInput("Iveskite sugeneruot failo namu darbu skaiciu: ", INT_MAX, 1);
        FileGen::gen_file(student_num, hw_num);
    }

    use_vector(settings);

    return 0;
}
