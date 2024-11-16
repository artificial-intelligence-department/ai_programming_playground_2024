#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    ofstream file(name, ios::out | ios::trunc);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;
    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    string file_name;
    string content;

    cout << "Введіть ім'я файлу: ";
    getline(cin, file_name);

    cout << "Введіть текст для запису в файл: ";
    getline(cin, content);

    FileOpResult result = write_to_file(file_name.c_str(), content.c_str());

    if (result == Success) {
        cout << "Текст успішно записано у файл." << endl;
    } else {
        cout << "Помилка запису у файл." << endl;
    }

    return 0;
}
