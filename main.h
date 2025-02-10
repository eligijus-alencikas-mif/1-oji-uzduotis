#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <limits>

#define NAME_LENGTH 15
#define HW_WEIGHT 0.4
#define EXAM_WEIGHT 0.6
#define GRADE_MAX 10

extern int numInput(const std::string &prompt, int limit_max = INT_MAX, int limit_min = INT_MIN);
extern std::string strInput(const std::string &prompt, int limit_max = INT_MAX, int limit_min = INT_MIN);

extern void use_vector(const bool &use_median);
extern void use_c_arr(const bool &use_median);

#endif //MAIN_H
