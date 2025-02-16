#include "main.h"

std::vector<Student> read_students() {
    std::vector<Student> students;
    std::fstream file(INPUT_FILE_NAME);

    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return students;
    }

    std::string word;
    int count = 0;
    while (file >> word) {
        count++;
        if (word == "Egz.") {
            break;
        }
    }

    Student student;
    while (file >> word) {
        student.f_name = word;
        file >> word;
        student.l_name = word;
        for (int i = 0; i < count-3; i++) {
            file >> word;
            student.hw_scores.push_back(stoi(word));
        }
        file >> word;
        student.exam_score = stoi(word);
        students.push_back(student);
    }

    file.close();
    return students;
}
