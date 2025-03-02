#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>

class Generator {
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
    public:
    std::string gen_f_name() const {
        return first_names[rand() % first_names.size()];
    }

    std::string gen_l_name() const {
        return last_names[rand() % last_names.size()];
    }

    std::string gen_name() const {
        return first_names[rand() % first_names.size()] + " " + last_names[rand() % last_names.size()];
    }

    std::vector<std::string> gen_names(unsigned long num_of_name) const {
        std::vector<std::string> names;
        for (unsigned long i = 0; i < num_of_name; i++) {
            names.push_back(gen_name());
        }
        return names;
    }

    static int rand_int(const int min, const int max) {
        return min + (rand() % (max - min + 1));
    }
};


#endif //GENERATOR_H
