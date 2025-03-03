#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <fstream>

class Stopwatch {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    long time_elapsed = 0;
    bool stopped = false;
    int id;

    public:
    explicit Stopwatch(const int _id) : id(_id) {}

    void stopwatch_start() {
        this->start = std::chrono::high_resolution_clock::now();
        stopped = false;
    }

    void stopwatch_pause() {
        this->end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->end - this->start);
        time_elapsed += duration.count();
        stopped = true;
    }

    long stopwatch_stop() {
        if (stopped) {
            return time_elapsed;
        }
        this->end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->end - this->start);
        time_elapsed += duration.count();
        stopped = true;
        return clear_time_elapsed();
    }

    long get_time_elapsed() const {
        return time_elapsed;
    }

    long clear_time_elapsed() {
        const long elapsed = time_elapsed;
        time_elapsed = 0;
        return elapsed;
    }

    int get_id() const {
        return id;
    }
};

class Timer {
    std::string content;
    std::vector<Stopwatch> watches;

public:

    void initialize_watch(const int watch_id) {
        watches.emplace_back(watch_id);
    }

    bool start_watch(const int watch_id) {
        for (auto& watch : watches) {
            if (watch.get_id() == watch_id) {
                watch.stopwatch_start();
                return true;
            }
        }
        return false;
    }

    bool pause_watch(const int watch_id) {
        for (auto& watch : watches) {
            if (watch.get_id() == watch_id) {
                watch.stopwatch_pause();
                return true;
            }
        }
        return false;
    }

    bool stop_watch(const int watch_id, std::string msg) {
        for (auto& watch : watches) {
            if (watch.get_id() == watch_id) {
                long time = watch.stopwatch_stop();
                msg += " (" + std::to_string(time) + " milliseconds)\n";
                content.append(msg);
                return true;
            }
        }
        return false;
    }

    long get_time_elapsed(const int watch_id) const {
        for (auto& watch : watches) {
            if (watch.get_id() == watch_id) {
                return watch.get_time_elapsed();
            }
        }
        return -1;
    }

    void write_to_file(const std::string& filename) {
        std::ofstream log_file(filename);
        log_file << this->content;
        log_file.close();
    }
};

#endif //TIMER_H
