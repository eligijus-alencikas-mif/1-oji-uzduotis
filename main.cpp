#include "main.h";

struct Student {
    std::string f_name, l_name;
    std::vector<int> hw_scores;
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};
};

using std::cout;

int main() {
    std::vector<Student> students;

    bool use_median = false;

    int choice = numInput("Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ", 2, 1);
    const int n = numInput("Iveskite studentu skaiciu: ", INT_MAX, 0);
    const int m = numInput("Iveskite namu darbu skaiciu: ", INT_MAX, 0);

    if (choice == 2) {
        use_median = true;
    }

    for (size_t i = 0; i < n; i++) {
        Student student;
        student.f_name = strInput("Iveskite " + std::to_string(i + 1) + " studento varda: ");
        student.l_name = strInput("Iveskite " + std::to_string(i + 1) + " studento pavarde: ");


        for (int j = 0; j < m; j++) {
            int hw_score;
            hw_score = numInput(
                "Iveskite " + std::to_string(i + 1) + " studento " + std::to_string(j + 1) + " namu darbo rezultata: ",
                GRADE_MAX, 0);
            student.hw_scores.push_back(hw_score);
        }

        student.exam_score = numInput("Iveskite egzamino rezultata: ", GRADE_MAX, 0);

        students.push_back(student);
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
            student.final_score_med = (static_cast<double>(scores[scores.size() / 2 - 1]) + static_cast<double>(scores[
                                           scores.size() / 2])) / 2.0;
        } else {
            student.final_score_med = scores[(scores.size() - 1) / 2];
        }

        double hw_avg;
        if (m == 0) {
            hw_avg = 0;
        } else {
            hw_avg = hw_sum / static_cast<double>(m);
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

    return 0;
}
