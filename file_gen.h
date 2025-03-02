#ifndef FILE_GEN_H
#define FILE_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include "main.h"

class FileGen {
    public:
    static void gen_file(int num_students, int num_hw) {
        std::ofstream file("kursiokai.txt");
        std::string content;
        std::string name_gap;
        int gap_size = std::to_string(num_students).length() + 1;
        for (int i = 0; i < gap_size; i++)
            name_gap.append(" ");

        // Header
        content.append("Vardas");
        content.append(name_gap);

        content.append("Pavarde");
        content.append(name_gap);

        for (int i = 1; i < num_hw + 1; ++i)
            content.append("ND" + std::to_string(i) + " ");
        content.append("Egzaminas\n");


        // Body
        for (int i = 1; i < num_students + 1; ++i) {
            content.append("Vardas" + std::to_string(i));
            for (int j = 0; j < gap_size - std::to_string(i).size(); ++j) {
                content.append(" ");
            }
            content.append("Pavarde" + std::to_string(i));
            for (int j = 0; j < gap_size - std::to_string(i).size(); ++j) {
                content.append(" ");
            }

            for (int j = 1; j < num_hw + 2; ++j) {
                std::string num = std::to_string(rand_int(0, GRADE_MAX));
                content.append(num);
                for (int k = 0; k < std::to_string(j).size() + 3 - num.length(); ++k) {
                    content.append(" ");
                }
            }

            content.append("\n");
        }

        file << content;
        file.close();
    }
};


#endif //FILE_GEN_H
