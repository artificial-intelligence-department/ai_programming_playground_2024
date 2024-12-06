#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream F1("F1.txt");

    if (!F1.is_open()) {
        cerr << "Не вдалося відкрити файл F1!" << endl;
        return 1;
    }

    ofstream F2("F2.txt");

    if (!F2.is_open()) {
        cerr << "Не вдалося відкрити файл F2!" << endl;
        return 1;
    }

    string line;
    while (getline(F1, line)) {
        if (!line.empty() && line[0] != 'A' && line[0] != 'a') {
            F2 << line << endl;
        }
    }
    F1.close();
    F2.close();

    ifstream F2_read("F2.txt");

    if (!F2_read.is_open()) {
        cerr << "Не вдалося відкрити файл F2!" << endl;
        return 1;
    }

    string first_word;

    if (getline(F2_read, line)) {
        stringstream ss(line);
        ss >> first_word; 
    }

    cout << "Кількість символів у першому слові F2: " << first_word.length() << endl;

    F2_read.close();

    return 0;
}