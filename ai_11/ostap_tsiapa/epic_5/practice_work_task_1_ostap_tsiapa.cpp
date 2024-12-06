#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure };

// Завдання №1 – Запис текстової стрічки у файл із заданим ім’ям
FileOpResult write_to_file(const char* name, const char* content) {
    if (name == nullptr || content == nullptr) {
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
    return Success;
}

// Завдання №2 – Копіювання вмісту файла у інший файл
FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream src(file_from, ios::binary);
    if (!src.is_open()) {
        return Failure;
    }

    ofstream dest(file_to, ios::binary);
    if (!dest.is_open()) {
        src.close();
        return Failure;
    }

    dest << src.rdbuf();

    if (dest.fail() || src.fail()) {
        src.close();
        dest.close();
        return Failure;
    }

    src.close();
    dest.close();
    return Success;
}

int main() {
    // Тест Завдання №1
    char filename1[256];
    char content[1024];
    cout << "Enter filename to write to: ";
    cin.getline(filename1, 256);
    cout << "Enter content to write: ";
    cin.getline(content, 1024);

    FileOpResult result1 = write_to_file(filename1, content);
    if (result1 == Success) {
        cout << "File written successfully." << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    // Тест Завдання №2
    char file_from[256];
    char file_to[256];
    cout << "Enter source filename to copy from: ";
    cin.getline(file_from, 256);
    cout << "Enter destination filename to copy to: ";
    cin.getline(file_to, 256);

    FileOpResult result2 = copy_file(file_from, file_to);
    if (result2 == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }

    return 0;
}
