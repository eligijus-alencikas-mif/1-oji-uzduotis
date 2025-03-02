#ifndef STUDENTS_CALC_H
#define STUDENTS_CALC_H

#include <vector>
#include "main.h"

class Calc_Students {
    public:

    static void calc_grades(std::vector<Student> &students) {
        for (Student &student: students) {
            set_student_avg(student);
            set_student_median(student);
        }
    }

    static void set_student_avg(Student &student) {
        if (student.hw_scores.empty()) {
            student.final_score_avg = EXAM_WEIGHT * static_cast<double>(student.exam_score);
            return;
        }

        double hw_sum = 0;
        double hw_avg = 0;

        for (const int hw_score: student.hw_scores) {
            hw_sum += hw_score;
        }

        hw_avg = hw_sum / static_cast<double>(student.hw_scores.size());
        student.final_score_avg = HW_WEIGHT * hw_avg + EXAM_WEIGHT * static_cast<double>(student.exam_score);
    }

    static void set_student_median(Student &student) {
        std::vector<int> scores = student.hw_scores;
        scores.push_back(student.exam_score);

        std::sort(scores.begin(), scores.end());

        if (scores.size() % 2 == 0) {
            student.final_score_med = (scores[(scores.size() / 2) - 1] + scores[scores.size() / 2]) / static_cast<double>(
                                          2);
        } else {
            student.final_score_med = scores[(scores.size() - 1) / 2];
        }
    }

    static void sort_students(std::vector<Student> &students, int sort_method) {
        switch (sort_method) {
            case 1:
                std::sort(students.begin(), students.end(), student_sort_f_name);
            break;
            case 2:
                std::sort(students.begin(), students.end(), student_sort_l_name);
            break;
            case 3:
                std::sort(students.begin(), students.end(), student_sort_avg);
            break;
            case 4:
                std::sort(students.begin(), students.end(), student_sort_med);
            break;
            default:
                break;
        }
    }

    static bool student_sort_f_name(Student const &lhs, Student const &rhs) {
        return lhs.f_name < rhs.f_name;
    }

    static bool student_sort_l_name(Student const &lhs, Student const &rhs) {
        return lhs.l_name < rhs.l_name;
    }

    static bool student_sort_avg(Student const &lhs, Student const &rhs) {
        return lhs.final_score_avg < rhs.final_score_avg;
    }

    static bool student_sort_med(Student const &lhs, Student const &rhs) {
        return lhs.final_score_med < rhs.final_score_med;
    }
};



#endif //STUDENTS_CALC_H
