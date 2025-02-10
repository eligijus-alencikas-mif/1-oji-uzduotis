#include "main.h"

int main() {

    int choice = numInput("Pasirinkite kodo versija (1 - naudojant tik vektorius, 2 - naudojant c masyva namu darbams saugoti): ");
    bool use_vec_ver = choice == 1;
    choice = numInput("Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ", 2, 1);
    bool use_median = choice != 1;

    if (use_vec_ver) {
        use_vector(use_median);
    }else {
        use_c_arr(use_median);
    }
    return 0;
}
