#include "main.h";

int main() {
    int choice = numInput("Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ", 2, 1);
    bool use_median = choice != 1;

    use_vector(use_median);

    return 0;
}
