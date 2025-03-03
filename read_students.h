#ifndef READ_STUDENTS_H
#define READ_STUDENTS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "main.h"


class File_students {
    int num_of_hw = 0;
    std::vector<Student> students;
    std::fstream file;
    std::string word;

    public:
    int iteration = 0;
    std::string error;

    File_students() {
        this->openFile();
        this->count_hw();
    }

    ~File_students() {
        this->closeFile();
    }

    void openFile() {
        try{
            this->file.open(INPUT_FILE_NAME);
            if (!this->file.is_open()) {
                std::cerr << "Nebuvo galima atidaryti failo" << "\n";
            }
        } catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    void closeFile() {
        try {
            this->file.close();
        } catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    void count_hw() {
        try {
            // this->num_of_hw = 0;
            // while (this->file >> this->word) {
            //     this->num_of_hw++;
            //     if (this->word == "Egz.") {
            //         break;
            //     }
            // }
            // this->num_of_hw -= 3;

            std::string line;
            std::getline(this->file, line);
            this->num_of_hw = 0;

            std::istringstream iss(line);

            while (iss >> this->word) {
                this->num_of_hw++;
                if (this->word == "Egz.") {
                    break;
                }
            }
            this->num_of_hw -= 3;
        }catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    std::vector<Student> read_students() {
        try {
            // int counter = 0;
            // while (this->file >> this->word) {
            //     Student student;
            //     student.f_name = this->word;
            //     this->file >> this->word;
            //     student.l_name = this->word;
            //
            //     for (int i = 0; i < this->num_of_hw; i++) {
            //         this->file >> this->word;
            //         student.hw_scores.push_back(stoi(this->word));
            //     }
            //
            //     this->file >> this->word;
            //
            //     student.exam_score = stoi(this->word);
            //     students.push_back(student);
            //     counter++;
            //
            //     if (counter == READ_LIMIT) {
            //         break;
            //     }
            //
            // }

            std::string line;
            int counter = 0;

            while (std::getline(this->file, line)) {
                std::istringstream iss(line);
                Student student;
                iss >> student.f_name >> student.l_name;
                for (int i = 0; i < this->num_of_hw; i++) {
                    std::string grade;
                    iss >> grade;
                    student.hw_scores.push_back(stoi(grade));
                }
                std::string exam_score;
                iss >> exam_score;
                student.exam_score = stoi(exam_score);
                this->students.push_back(student);
                counter++;

                if (counter == READ_LIMIT) {
                    break;
                }
            }

            return this->students;
        } catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
            return students;
        }
    }

    void clear_students() {
        this->students.clear();
    }

};

#endif // READ_STUDENTS_H