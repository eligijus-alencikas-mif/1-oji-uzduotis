#include "main.h"

using std::cin;
using std::cout;

int numInput(const std::string &prompt, int limit_max /*= INT_MAX*/, int limit_min /*= INT_MIN*/) {
    int num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (num > limit_max) {
                cout << "Ivestas per didelis skaicius\n";
                continue;
            }
            if (num < limit_min) {
                cout << "Ivestas per mazas skaicius\n";
                continue;
            }
            break;
        } else {
            cout << "Klaidinga ivestis\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return num;
}

std::string strInput(const std::string &prompt, int limit_max /*= INT_MAX*/, int limit_min /*= INT_MIN*/) {
    std::string str;

    while (true) {
        cout << prompt;
        if (cin >> str) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (static_cast<int>(str.length()) > limit_max) {
                cout << "Per ilga ivestis\n";
                continue;
            }
            if (static_cast<int>(str.length()) < limit_min) {
                cout << "Per trumpa ivestis\n";
                continue;
            }
            break;
        } else {
            cout << "Klaidinga ivestis\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return str;
}