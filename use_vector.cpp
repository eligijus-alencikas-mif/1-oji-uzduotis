#include "main.h"
#include "read_students.h"
#include "output_students.h"

using std::cout;

void set_student_avg(Student &student);
void set_student_median(Student &student);
bool student_sort_avg(Student const &lhs, Student const &rhs);
bool student_sort_med(Student const &lhs, Student const &rhs);
bool student_sort_f_name(Student const &lhs, Student const &rhs);
bool student_sort_l_name(Student const &lhs, Student const &rhs);
void read_user_input(const bool &generate_names, const bool &generate_grades, std::vector<Student> &students);

void use_vector(const bool &generate_names, const bool &generate_grades, const bool &get_students_from_file,
                const int sort_method, const bool output_to_file) {
    Timer timer;
    File_students file;
    Output_students output(output_to_file);
    timer.timer_start();

    int counter = 0;

    while (true) {
        std::vector<Student> students;

        if (get_students_from_file) {
            students = file.read_students();
        }else {
            read_user_input(generate_names, generate_grades, students);
        }

        if (students.empty()) {
            break;
        }


        for (Student &student: students) {
            set_student_avg(student);
            set_student_median(student);
        }


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

        output.output_students(students);
        counter++;
        file.clear_students();
    }
    timer.timer_stop();
    timer.time_include("Time taken:");
    timer.timer_write();
}

void set_student_avg(Student &student) {
    if (student.hw_scores.empty()) {
        student.final_score_avg = 0;
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

void set_student_median(Student &student) {
    std::vector<int> scores = student.hw_scores;
    scores.push_back(student.exam_score);

    std::nth_element(scores.begin(), scores.begin() + scores.size() / 2, scores.end());

    if (scores.size() % 2 == 0) {
        student.final_score_med = (scores[(scores.size() / 2) - 1] + scores[scores.size() / 2]) / static_cast<double>(
                                      2);
    } else {
        student.final_score_med = scores[(scores.size() - 1) / 2];
    }
}

bool student_sort_f_name(Student const &lhs, Student const &rhs) {
    return lhs.f_name < rhs.f_name;
}

bool student_sort_l_name(Student const &lhs, Student const &rhs) {
    return lhs.l_name < rhs.l_name;
}

bool student_sort_avg(Student const &lhs, Student const &rhs) {
    return lhs.final_score_avg < rhs.final_score_avg;
}

bool student_sort_med(Student const &lhs, Student const &rhs) {
    return lhs.final_score_med < rhs.final_score_med;
}

void read_user_input(const bool &generate_names, const bool &generate_grades, std::vector<Student> &students) {
    while (true) {
        Student student;
        if (generate_names) {
            student.f_name = gen_f_name();
            student.l_name = gen_l_name();
            cout << "Sugeneruotas studento vardas " + student.f_name + " " + student.l_name + "\n";
        } else {
            student.f_name = strInput("Iveskite " + std::to_string(students.size() + 1) + " studento varda: ");
            student.l_name = strInput("Iveskite " + std::to_string(students.size() + 1) + " studento pavarde: ");
        }
        if (generate_grades) {
            int n = numInput("Kiek ND pazymiu generuoti studentui " + std::to_string(students.size() + 1) + "? : ",
                             INT_MAX, 0);
            cout << "Namu darbu pazymiai: ";
            for (int i = 0; i < n; i++) {
                student.hw_scores.push_back(rand_int(0, GRADE_MAX));
                cout << student.hw_scores.at(i) << " ";
            }
            cout << "\n";
        }
        while (!generate_grades) {
            if (
                student.hw_scores.empty()
                && !numInput("Ar norite ivesti namu darbu rezultatus? (1 - taip, 0 - ne): ", 1, 0)
            )
                break;
            int hw_score;
            hw_score = numInput(
                "Iveskite " + std::to_string(students.size() + 1) + " studento " + std::to_string(
                    student.hw_scores.size() + 1) + " namu darbo rezultata: ",
                GRADE_MAX, 0);
            student.hw_scores.push_back(hw_score);

            if (!numInput("Ar norite ivesti dar viena namu darba? (1 - taip, 0 - ne): ", 1, 0))
                break;
        }
        if (generate_grades) {
            student.exam_score = rand_int(0, GRADE_MAX);
            cout << "Egzamino pazymys: " << student.exam_score << "\n";
        } else {
            student.exam_score = numInput("Iveskite egzamino rezultata: ", GRADE_MAX, 0);
        }

        students.push_back(student);

        if (!numInput("Ar norite ivesti dar viena studenta? (1 - taip, 0 - ne): ", 1, 0))
            break;
    }
}