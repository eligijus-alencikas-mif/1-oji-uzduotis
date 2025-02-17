#include "main.h"

int main() {
    int choice = numInput("Pasirinkte duomenu generavimo metoda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba): ", 5, 1);

    bool generate_names = false;
    bool generate_grades = false;
    bool get_students_from_file = false;

    switch (choice) {
        case 1:
            generate_names = false;
            generate_grades = false;
            get_students_from_file = false;
        break;
        case 2:
            generate_names = true;
        break;
        case 3:
            generate_names = true;
            generate_grades = true;
        break;
        case 4:
            get_students_from_file = true;
        break;
        default:
            return 0;
    }

    int sort_method = numInput("Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ", 5, 1);
    bool output_to_file = numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) == 2;

    use_vector(generate_names, generate_grades, get_students_from_file, sort_method, output_to_file);

    return 0;
}
