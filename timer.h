#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <fstream>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    std::string content;


public:
    void timer_start() {
        start = std::chrono::high_resolution_clock::now();
    }

    void timer_stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    void time_include(std::string msg) {
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(this->end - this->start);
        msg += " (" + std::to_string(duration.count()) + " microseconds)\n";
        content.append(msg);
    }

    void timer_write() {
        std::ofstream log_file("times.txt");
        log_file << this->content;
        log_file.close();
    }
};

#endif //TIMER_H
