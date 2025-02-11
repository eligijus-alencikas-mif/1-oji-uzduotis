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

extern void use_vector(const bool &use_median, const bool &generate_names, const bool &generate_grades);
extern void use_c_arr(const bool &use_median, const bool &generate_names, const bool &generate_grades);

extern std::string gen_name();
extern std::vector<std::string> gen_names(unsigned long num_of_name);
extern int rand_int(int min, int max);
extern std::string gen_f_name();
extern std::string gen_l_name();


#endif //MAIN_H
