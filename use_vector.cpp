#include "main.h"

using std::cout;

void use_vector(const bool &use_median, const bool &generate_names, const bool &generate_grades, const bool &get_students_from_file) {
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
            << std::setw(NAME_LENGTH) << std::left << "Pavarde";
    if (use_median) {
        cout << "Galutinis (Med.)";
    } else {
        cout << "Galutinis (Vid.)";
    }
    cout << '\n';
    const size_t line_length = (NAME_LENGTH * 2) + 16;
    for (size_t i = 0; i < line_length; i++) {
        cout << "-";
    }
    cout << '\n';

    for (Student &student: students) {
        double hw_sum = 0;

        for (int hw_score: student.hw_scores) {
            hw_sum += hw_score;
        }

        std::vector<int> scores = student.hw_scores;
        scores.push_back(student.exam_score);

        std::sort(scores.begin(), scores.end());

        if (scores.size() % 2 == 0) {
            student.final_score_med = (scores[(scores.size() / 2) - 1] + scores[scores.size() / 2])/static_cast<double>(2);
        } else {
            student.final_score_med = scores[(scores.size() - 1) / 2];
        }

        double hw_avg;
        if (student.hw_scores.empty()) {
            hw_avg = 0;
        } else {
            hw_avg = hw_sum / static_cast<double>(student.hw_scores.size());
        }

        student.final_score_avg = HW_WEIGHT * hw_avg + EXAM_WEIGHT * static_cast<double>(student.exam_score);

        cout << std::setw(NAME_LENGTH) << std::left << student.f_name
                << std::setw(NAME_LENGTH) << std::left << student.l_name;
        if (use_median) {
            cout << std::setprecision(3) << student.final_score_med;
        } else {
            cout << std::setprecision(3) << student.final_score_avg;
        }
        cout << '\n';
    }
}
