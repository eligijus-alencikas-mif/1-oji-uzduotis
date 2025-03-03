#ifndef FILE_GEN_H
#define FILE_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include "generator.h"
#include "constant_definitions.h"
#include "timer.h"

class FileGen {
public:
    static void gen_file(std::uint64_t num_students, std::uint64_t num_hw) {
        Timer t;
        t.initialize_watch(1);

        t.start_watch(1);
        Generator gen;
        std::ofstream file("kursiokai.txt");
        std::string content;
        std::uint64_t reserve_size = (num_students * 35 + 7 * num_hw * num_students) + 1000;
        content.reserve(reserve_size);
        std::string name_gap;
        int gap_size = std::to_string(num_students).length() + 1;
        for (int i = 0; i < gap_size; i++)
            name_gap.append(" ");
        t.stop_watch(1, "initialize variables:");

        t.start_watch(1);

        // Header
        content.append("Vardas");
        content.append(name_gap);

        content.append("Pavarde");
        content.append(name_gap);

        for (int i = 1; i < num_hw + 1; ++i)
            content.append("ND" + std::to_string(i) + " ");
        content.append("Egzaminas\n");
        t.stop_watch(1, "generate header:");

        t.start_watch(1);
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
                std::string num = std::to_string(Generator::rand_int(0, GRADE_MAX));
                content.append(num);
                for (int k = 0; k < std::to_string(j).size() + 3 - num.length(); ++k) {
                    content.append(" ");
                }
            }

            content.append("\n");
        }
        t.stop_watch(1, "generate body:");

        t.start_watch(1);
        file << content;
        t.stop_watch(1, "write file:");
        t.start_watch(1);
        content.clear();
        file.close();
        t.stop_watch(1, "clear vector and close file:");
        t.write_to_file("generated.txt");
    }
};


#endif //FILE_GEN_H
