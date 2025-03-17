#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>

struct Student {
    std::string f_name, l_name;
    std::vector<int> hw_scores;
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};
};

#endif //STUDENT_H
