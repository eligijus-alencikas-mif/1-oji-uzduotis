#include "main.h"

int main() {
    // read_students();
    // return 0;
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

    choice = numInput("Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ", 2, 1);
    bool use_median = choice != 1;

    use_vector(use_median, generate_names, generate_grades, get_students_from_file);

    return 0;
}
