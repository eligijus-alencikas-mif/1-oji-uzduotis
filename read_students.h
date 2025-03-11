#ifndef READ_STUDENTS_H
#define READ_STUDENTS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "student_def.h"

class File_students {
    int num_of_hw = 0;
    std::fstream file;
    std::string word;

public:
    int iteration = 0;
    std::string error;

    explicit File_students(const std::string& file_name);
    ~File_students();

    void openFile(const std::string& file_name);
    void closeFile();
    void count_hw();
    void read_students(std::vector<Student> &students);
};

#endif // READ_STUDENTS_H
