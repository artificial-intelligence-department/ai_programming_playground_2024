#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (!file_from || !file_to) {
        return Failure;
    }

    ifstream input(file_from, ios::in);
    if (!input) {
        return Failure;
    }

    ofstream output(file_to, ios::out);
    if (!output) {
        return Failure; 
    }

    string line;
    while (getline(input, line)) {
        output << line << "\n"; 
    }

    if (!output.good()) {
        return Failure; 
    }

    input.close();
    output.close();

    if (!input.good() || !output.good()) {
        return Failure; 
    }

    return Success;
}

int main() {
    string file_from, file_to;

    cout << "Введіть ім'я вихідного файлу: ";
    getline(cin, file_from);

    cout << "Введіть ім'я цільового файлу: ";
    getline(cin, file_to);

    FileOpResult result = copy_file(file_from.c_str(), file_to.c_str());
    if (result == Success) {
        cout << "Файл успішно скопійовано.\n";
    } else {
        cout << "Сталася помилка при копіюванні файлу.\n";
    }

    return 0;
}

