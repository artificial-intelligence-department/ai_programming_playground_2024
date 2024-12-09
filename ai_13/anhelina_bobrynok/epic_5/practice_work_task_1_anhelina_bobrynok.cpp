#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (!name || !content) {
        return Failure;
    }

    ofstream file(name, ios::out); 
    if (!file) {
        return Failure;
    }

    file << content;
    if (!file.good()) {
        return Failure;
    }

    file.close();
    if (!file.good()) {
        return Failure;
    }

    return Success;
}

int main() {
    string filename;
    string content;

    cout << "Введіть ім'я файлу: ";
    getline(cin, filename);

    cout << "Введіть вміст для запису у файл: ";
    getline(cin, content);

    FileOpResult result = write_to_file(filename.c_str(), content.c_str());
    if (result == Success) {
        cout << "Файл успішно створено і записано.\n";
    } else {
        cout << "Сталася помилка при записі у файл.\n";
    }

    return 0;
}
