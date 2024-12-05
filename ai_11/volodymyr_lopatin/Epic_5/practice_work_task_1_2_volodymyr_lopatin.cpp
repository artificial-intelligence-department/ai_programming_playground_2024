#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(const char* name, const char* content) {
    if (name == nullptr || content == nullptr || strlen(name) == 0) {
        return Failure;
    }
    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }
    file << content;
    if (file.fail()) {
        file.close();
        return Failure;
    }
    file.close();
    if (file.fail()) {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (file_from == nullptr || file_to == nullptr || 
        strlen(file_from) == 0 || strlen(file_to) == 0) {
        return Failure;
    }

    ifstream src(file_from, ios::binary);
    if (!src.is_open()) {
        return Failure;
    }

    ofstream input(file_to, ios::binary);
    if (!input.is_open()) {
        return Failure;
    }
    input << src.rdbuf();
    if (src.fail() || input.fail()) {
        src.close();
        input.close();
        return Failure;
    }
    src.close();
    input.close();
    if (src.fail() || input.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    char filename[256];
    char content[1024];
    cout << "Введіть ім'я файлу для запису: ";
    cin.getline(filename, sizeof(filename));
    cout << "Введіть текст для запису у файл: ";
    cin.getline(content, sizeof(content));
    if (write_to_file(filename, content) == Success) {
        cout << "Файл успішно створено і записано." << endl;
    } else {
        cerr << "Помилка запису у файл." << endl;
        return 1;
    }
    char file_from[256], file_to[256];
    cout << "Введіть ім'я файлу-джерела для копіювання: ";
    cin.getline(file_from, sizeof(file_from));
    cout << "Введіть ім'я файлу-призначення: ";
    cin.getline(file_to, sizeof(file_to));
    if (copy_file(file_from, file_to) == Success) {
        cout << "Файл успішно скопійовано." << endl;
    } else {
        cerr << "Помилка копіювання файлу." << endl;
        return 1;
    }
    return 0;
}
