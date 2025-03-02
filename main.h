#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

#define NAME_LENGTH 17
#define HW_WEIGHT 0.4
#define EXAM_WEIGHT 0.6
#define GRADE_MAX 10
#define INPUT_FILE_NAME "kursiokai.txt"

struct Process_settings {
    bool generate_names = false;
    bool generate_grades = false;
    bool get_students_from_file = false;
    int sort_method = 0;
    bool output_to_file = false;
    bool generate_input_file = false;
    int input_file_student_num = 0;
    int input_file_student_hw = 0;
};

struct Student {
    std::string f_name, l_name;
    std::vector<int> hw_scores;
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};
};

#endif //MAIN_H
