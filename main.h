#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <limits>
#include <fstream>

#define NAME_LENGTH 17
#define HW_WEIGHT 0.4
#define EXAM_WEIGHT 0.6
#define GRADE_MAX 10
#define INPUT_FILE_NAME "kursiokai.txt"


struct Student {
    std::string f_name, l_name;
    std::vector<int> hw_scores;
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};
};

// inputs.cpp

extern int numInput(const std::string &prompt, int limit_max = INT_MAX, int limit_min = INT_MIN);
extern std::string strInput(const std::string &prompt, int limit_max = INT_MAX, int limit_min = INT_MIN);

// use_vector.cpp

extern void use_vector(const bool &generate_names, const bool &generate_grades, const bool &get_students_from_file);

// stud_gen.cpp

extern std::string gen_name();
extern std::vector<std::string> gen_names(unsigned long num_of_name);
extern int rand_int(int min, int max);
extern std::string gen_f_name();
extern std::string gen_l_name();

// read_students.cpp

extern std::vector<Student> read_students();

#endif //MAIN_H
