#include "cl_students.h"

#include "constant_definitions.h"

std::list<Student> CL_Students::get_user_input(const bool &generate_names, const bool &generate_grades)
{
    std::list<Student> students;
    while (true)
    {
        Student student;
        if (generate_names)
        {
            gen_names(student);
        }
        else
        {
            CL_names(student, students.size());
        }
        if (generate_grades)
        {
            gen_grades(student, students.size());
        }
        else
        {
            CL_grades(student, students.size());
        }

        students.push_back(student);

        if (!CLInputs::numInput("Ar norite ivesti dar viena studenta? (1 - taip, 0 - ne): ", 1, 0))
            break;
    }
    return students;
}

void CL_Students::gen_names(Student &student)
{
    const Generator gen;
    student.f_name = gen.gen_f_name();
    student.l_name = gen.gen_l_name();
    cout << "Sugeneruotas studento vardas " + student.f_name + " " + student.l_name + "\n";
}

void CL_Students::CL_names(Student &student, const int students_size)
{
    student.f_name = CLInputs::strInput(
        "Iveskite " + std::to_string(students_size + 1) + " studento varda: ");
    student.l_name = CLInputs::strInput(
        "Iveskite " + std::to_string(students_size + 1) + " studento pavarde: ");
}

void CL_Students::gen_grades(Student &student, const int students_size)
{
    const int n = CLInputs::numInput(
        "Kiek ND pazymiu generuoti studentui " + std::to_string(students_size + 1) + "? : ",
        int_lim::max(), 0);
    cout << "Namu darbu pazymiai: ";
    for (int i = 0; i < n; i++)
    {
        student.hw_scores.push_back(Generator::rand_int(0, GRADE_MAX));
        cout << student.hw_scores.at(i) << " ";
    }
    cout << "\n";

    student.exam_score = Generator::rand_int(0, GRADE_MAX);
    cout << "Egzamino pazymys: " << student.exam_score << "\n";
}

void CL_Students::CL_grades(Student &student, const int students_size)
{
    while (true)
    {
        if (student.hw_scores.empty())
        {
            if (!CLInputs::numInput("Ar norite ivesti namu darbu rezultatus? (1 - taip, 0 - ne): ", 1, 0))
            {
                break;
            }
        }
        else if (!CLInputs::numInput("Ar norite ivesti dar viena namu darba? (1 - taip, 0 - ne): ", 1, 0))
        {
            break;
        }

        int hw_score;
        hw_score = CLInputs::numInput(
            "Iveskite " + std::to_string(students_size + 1) + " studento " + std::to_string(student.hw_scores.size() + 1) + " namu darbo rezultata: ",
            GRADE_MAX, 0);

        student.hw_scores.push_back(hw_score);
    }
    student.exam_score = CLInputs::numInput("Iveskite egzamino rezultata: ", GRADE_MAX, 0);
}