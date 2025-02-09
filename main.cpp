#include "main.h";

struct Student
{
	std::string f_name, l_name;
	std::vector<int> hw_scores;
	int exam_score;
	double final_score_avg;
	double final_score_med;
};

int main()
{
	std::vector<Student> students;

	int n, m;
	bool use_median = false;
	int choice = 1;

	cout << "Pasirinkite galutinio balo skaiciavimo buda (1 - vidurkis, 2 - mediana): ";
	cin >> choice;
	cout << "Iveskite studentu skaiciu: ";
	cin >> n;
	cout << "Iveskite namu darbu skaiciu: ";
	cin >> m;

	if (choice == 2)
	{
		use_median = true;
	}

	for (size_t i = 0; i < n; i++)
	{
		Student student;
		cout << "Iveskite " << i + 1 << " studento varda: ";
		cin >> student.f_name;
		cout << "Iveskite " << i + 1 << " studento pavarde: ";
		cin >> student.l_name;

		for (int j = 0; j < m; j++)
		{
			int hw_score;
			cout << "Iveskite " << i + 1 << " studento " << j + 1 << " namu darbo rezultata: ";
			cin >> hw_score;
			student.hw_scores.push_back(hw_score);
		}

		cout << "Iveskite egzamino rezultata: ";
		cin >> student.exam_score;

		students.push_back(student);
	}

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
	const size_t line_length = (NAME_LENGTH * 2) + 16;
	for (size_t i = 0; i < line_length; i++)
	{
		cout << "-";
	}
	cout << '\n';

	for (Student &student : students)
	{
		double hw_sum = 0;

		for (int hw_score : student.hw_scores)
		{
			hw_sum += hw_score;
		}

		std::vector<int> scores = student.hw_scores;
		scores.push_back(student.exam_score);

		std::sort(scores.begin(), scores.end());

		if (scores.size() % 2 == 0)
		{
			student.final_score_med = ((double)scores[scores.size() / 2 - 1] + (double)scores[scores.size() / 2]) / 2.0;
		}
		else
		{
			student.final_score_med = scores[(scores.size() - 1) / 2];
		}

		double hw_avg;
		if (m == 0)
		{
			hw_avg = 0;
		}
		else
		{
			hw_avg = hw_sum / (double)m;
		}

		student.final_score_avg = HW_WEIGHT * hw_avg + EXAM_WEIGHT * (double)student.exam_score;

		cout << std::setw(NAME_LENGTH) << std::left << student.f_name
			 << std::setw(NAME_LENGTH) << std::left << student.l_name;
		if (use_median)
		{
			cout << std::setprecision(3) << student.final_score_med;
		}
		else
		{
			cout << std::setprecision(3) << student.final_score_avg;
		}
		cout << '\n';
	}

	return 0;
}