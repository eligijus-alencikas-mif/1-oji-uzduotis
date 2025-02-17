#ifndef READ_STUDENTS_H
#define READ_STUDENTS_H

#include <fstream>
#include <string>
#include <vector>

class File_students {
    int num_of_hw = 0;
    std::vector<Student> students;
    std::fstream file;
    std::string word;

    public:
    int iteration = 0;

    File_students() {
        this->openFile();
        this->count_hw();
    }

    ~File_students() {
        this->closeFile();
    }

    void openFile() {
        this->file.open(INPUT_FILE_NAME);
        if (!this->file.is_open()) {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    void closeFile() {
        this->file.close();
    }

    void count_hw() {
        this->num_of_hw = 0;
        while (this->file >> this->word) {
            this->num_of_hw++;
            if (this->word == "Egz.") {
                break;
            }
        }
        this->num_of_hw -= 3;
    }

    std::vector<Student> read_students() {
        int counter = 0;
        while (this->file >> this->word) {
            Student student;
            student.f_name = this->word;
            this->file >> this->word;
            student.l_name = this->word;

            for (int i = 0; i < this->num_of_hw; i++) {
                this->file >> this->word;
                student.hw_scores.push_back(stoi(this->word));
            }

            this->file >> this->word;

            student.exam_score = stoi(this->word);
            students.push_back(student);
            counter++;

            if (counter == READ_LIMIT) {
                break;
            }

        }

        return students;
    }

    void clear_students() {
        this->students.clear();
    }

};

#endif // READ_STUDENTS_H