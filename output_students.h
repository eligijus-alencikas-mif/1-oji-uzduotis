#ifndef OUTPUT_STUDENTS_H
#define OUTPUT_STUDENTS_H
#include <iomanip>


using std::cout;

class Output_students {
    std::ofstream output;
    bool out_to_file;
    bool header_done = false;

    public:
    std::string error;

    Output_students(const bool out_to_file) {
        this->out_to_file = out_to_file;
        if (out_to_file) {
            output = std::ofstream();
            this->open_file();
        }
    }

    ~Output_students() {
        this->close_file();
    }

    void open_file() {
        try {
            output.open("out.txt");
        } catch (const std::exception &e) {
                std::cerr << "Ivyko klaida" << "\n";
                this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    void close_file() {
        try {
            output.close();
        } catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    void output_students(std::vector<Student> const &students) {
        try {
            if (this->out_to_file) {
                this->output_file(students);
            }else {
                this->output_terminal(students);
            }
        } catch (const std::exception &e) {
            std::cerr << "Ivyko klaida" << "\n";
            this->error = "ERROR: " + static_cast<std::string>(e.what());
        }
    }

    void output_file(std::vector<Student> const &students) {
        if (!header_done) {
            this->output
            << std::setw(NAME_LENGTH) << std::left << "Vardas"
            << std::setw(NAME_LENGTH) << std::left << "Pavarde"
            << "Galutinis (Vid.) Galutinis (Med.)"
            << '\n';
            const size_t line_length = (NAME_LENGTH * 2) + 33;
            for (size_t i = 0; i < line_length; i++) {
                this->output << "-";
            }
            this->output << '\n';
            header_done = true;
        }

        for (const Student &student : students) {
            this->output << std::setw(NAME_LENGTH) << std::left << student.f_name
                    << std::setw(NAME_LENGTH) << std::left << student.l_name
                    << std::setw(17) << std::left << std::setprecision(3) << student.final_score_avg
                    << std::setprecision(3) << student.final_score_med
                    << '\n';
        }
    }

    void output_terminal(std::vector<Student> const &students) {
        if (!header_done) {
            cout << '\n'
                << std::setw(NAME_LENGTH) << std::left << "Vardas"
                << std::setw(NAME_LENGTH) << std::left << "Pavarde"
                << "Galutinis (Vid.) Galutinis (Med.)"
                << '\n';
            const size_t line_length = (NAME_LENGTH * 2) + 33;
            for (size_t i = 0; i < line_length; i++) {
                cout << "-";
            }
            cout << '\n';
            header_done = true;
        }

        for (Student const &student: students) {
            cout << std::setw(NAME_LENGTH) << std::left << student.f_name
                    << std::setw(NAME_LENGTH) << std::left << student.l_name
                    << std::setw(17) << std::left << std::setprecision(3) << student.final_score_avg
                    << std::setprecision(3) << student.final_score_med
                    << '\n';
        }
    }
};

#endif //OUTPUT_STUDENTS_H
