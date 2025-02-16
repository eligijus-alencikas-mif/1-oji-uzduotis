#include "main.h"

int main() {
    int choice = numInput("Pasirinkte duomenu generavimo metoda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba): ", 4, 1);

    bool generate_names = false;
    bool generate_grades = false;
    if (choice == 2) {
        generate_grades = true;
    }else if (choice == 3) {
        generate_names = true;
        generate_grades = true;
    }else if (choice == 4) {
        return 0;
    }

    choice = numInput("Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ", 2, 1);
    bool use_median = choice != 1;

    use_vector(use_median, generate_names, generate_grades);

    return 0;
}
