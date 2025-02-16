#include "main.h"

using std::cout;

bool student_sort_f_name(Student const &lhs, Student const &rhs);
bool student_sort_l_name(Student const &lhs, Student const &rhs);
void set_student_avg(Student &student);
void set_student_median(Student &student);
bool student_sort_avg(Student const &lhs, Student const &rhs);
bool student_sort_med(Student const &lhs, Student const &rhs);

void use_vector(const bool &generate_names, const bool &generate_grades, const bool &get_students_from_file, const int sort_method) {
    std::vector<Student> students;

    if (get_students_from_file) {
        students = read_students();
    }

    while (!get_students_from_file) {
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

    cout << '\n'
            << std::setw(NAME_LENGTH) << std::left << "Vardas"
            << std::setw(NAME_LENGTH) << std::left << "Pavarde"
            << "Galutinis (Vid.) Galutinis (Med.)";
    cout << '\n';
    const size_t line_length = (NAME_LENGTH * 2) + 33;
    for (size_t i = 0; i < line_length; i++) {
        cout << "-";
    }
    cout << '\n';

    for (Student &student : students) {
        set_student_avg(student);
        set_student_median(student);
    }

    if (sort_method == 1) {
        std::sort(students.begin(), students.end(), student_sort_f_name);
    }else if (sort_method == 2) {
        std::sort(students.begin(), students.end(), student_sort_l_name);
    }else if (sort_method == 3) {
        std::sort(students.begin(), students.end(), student_sort_avg);
    }else if (sort_method == 4) {
        std::sort(students.begin(), students.end(), student_sort_med);
    }

    for (Student const &student: students) {
        cout << std::setw(NAME_LENGTH) << std::left << student.f_name
                << std::setw(NAME_LENGTH) << std::left << student.l_name
                << std::setw(17) << std::left << std::setprecision(3) << student.final_score_avg
                << std::setprecision(3) << student.final_score_med;
        cout << '\n';
    }
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

    std::sort(scores.begin(), scores.end());

    if (scores.size() % 2 == 0) {
        student.final_score_med = (scores[(scores.size() / 2) - 1] + scores[scores.size() / 2])/static_cast<double>(2);
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