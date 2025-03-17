#ifndef OUTPUT_STUDENTS_H
#define OUTPUT_STUDENTS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>

#include "constant_definitions.h"
#include "student_def.h"

struct Student;
using std::cout;

class Output_students
{
    std::ofstream output;

public:
    std::string error;

    Output_students();
    ~Output_students();

    void open_file(const std::string &file_name);
    void close_file();
    void output_students(std::deque<Student> const &students, const bool &out_to_file);
    void output_file(std::deque<Student> const &students);
    void output_terminal(std::deque<Student> const &students);
};

#endif // OUTPUT_STUDENTS_H
