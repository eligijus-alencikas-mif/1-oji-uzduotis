#include "main.h"

using std::cout;

struct Student
{
    std::string f_name, l_name;
    int *hw_scores = nullptr;
	int hw_scores_size{};
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};

	explicit Student(int hw_size = 0) {
		hw_scores_size = hw_size;
		if (hw_scores_size > 0) {
			hw_scores = new int[hw_scores_size];
		}
	}
};

void use_c_arr(const bool &use_median) {
	std::vector<Student> students;

	for (size_t i = 0; true; i++)
	{
		std::vector<int> hw_scores;
		std::string tmp_f_name = strInput("Iveskite " + std::to_string(students.size() + 1) + " studento varda: ");
		std::string tmp_l_name = strInput("Iveskite " + std::to_string(students.size() + 1) + " studento pavarde: ");

		for (int j = 0; true; j++)
		{
			if (j == 0) {
				if (!numInput("Ar norite ivesti namu darbu rezultatus? (1 - taip, 0 - ne): ", 1, 0))
					break;
			}
			int score = numInput("Iveskite " + std::to_string(i + 1) + " studento " + std::to_string(j + 1) + " namu darbo rezultata: ", GRADE_MAX, 0);
			hw_scores.push_back(score);
			// student.hw_scores[student.hw_scores_size] = numInput("Iveskite " + std::to_string(i + 1) + " studento " + std::to_string(j + 1) + " namu darbo rezultata: ", GRADE_MAX, 0);
			// student.hw_scores_size++;

			if (!numInput("Ar norite ivesti dar viena namu darba? (1 - taip, 0 - ne): ", 1, 0))
				break;
		}
		Student student(hw_scores.size());

		student.exam_score = numInput("Iveskite egzamino rezultata: ", GRADE_MAX, 0);

		student.f_name = tmp_f_name;
		student.l_name = tmp_l_name;
		student.hw_scores = hw_scores.data();

		students.push_back(student);

		if (!numInput("Ar norite ivesti dar viena studenta? (1 - taip, 0 - ne): ", 1, 0))
			break;
	}

	// output

	cout << '\n'
		 << std::setw(NAME_LENGTH) << std::left << "Vardas"
		 << std::setw(NAME_LENGTH) << std::left << "Pavarde";
	if (use_median)
	{
		cout << "Galutinis (Med.)";
	}
	else
	{
		cout << "Galutinis (Vid.)";
	}
	cout << '\n';

	size_t line_length = (NAME_LENGTH * 2) + 16;
	for (size_t i = 0; i < line_length; i++)
	{
		cout << "-";
	}
	cout << '\n';

	for (size_t i = 0; i < students.size(); i++)
	{
		double hw_sum = 0;

		for (size_t j = 0; j < students[i].hw_scores_size; j++)
		{
			// hw_sum += students[i].hw_scores[j];
		}

		std::vector<int> scores(students[i].hw_scores, students[i].hw_scores + students[i].hw_scores_size);
		scores.push_back(students[i].exam_score);

		std::sort(scores.begin(), scores.end());

		if (scores.size() % 2 == 0)
		{
			students[i].final_score_med = ((double)scores[scores.size() / 2 - 1] + (double)scores[scores.size() / 2]) / 2.0;
		}
		else
		{
			students[i].final_score_med = scores[(scores.size() - 1) / 2];
		}

		double hw_avg = (students[i].hw_scores_size == 0) ? 0 : hw_sum / (double)students[i].hw_scores_size;

		students[i].final_score_avg = HW_WEIGHT * hw_avg + EXAM_WEIGHT * (double)students[i].exam_score;

		cout << std::setw(NAME_LENGTH) << std::left << students[i].f_name
			 << std::setw(NAME_LENGTH) << std::left << students[i].l_name;
		if (use_median)
		{
			cout << std::setprecision(3) << students[i].final_score_med;
		}
		else
		{
			cout << std::setprecision(3) << students[i].final_score_avg;
		}
		cout << '\n';
	}
}