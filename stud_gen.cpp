#include "main.h"

const std::vector<std::string> first_names = {
    "Eligijus",
    "Jonas",
    "Vytautas",
    "Antanas",
    "Tomas",
    "Juozas",
    "Ona",
    "Irena",
    "Janina",
    "Kristina",
    "Danute"
};

const std::vector<std::string> last_names = {
    "Alencikas",
    "Jodikevicius",
    "Jasiunskas",
    "Stasiulionis",
    "Budvila",
    "Davailis",
    "Ignataitis",
    "Girla",
    "Numeika",
    "Kabaila",
    "Milakna"
};

std::string gen_f_name() {
    return first_names[rand() % first_names.size()];
}

std::string gen_l_name() {
    return last_names[rand() % last_names.size()];
}

std::string gen_name() {
    return first_names[rand() % first_names.size()] + " " + last_names[rand() % last_names.size()];
}

std::vector<std::string> gen_names(unsigned long num_of_name) {
    std::vector<std::string> names;
    for (unsigned long i = 0; i < num_of_name; i++) {
        names.push_back(gen_name());
    }
    return names;
}

int rand_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}