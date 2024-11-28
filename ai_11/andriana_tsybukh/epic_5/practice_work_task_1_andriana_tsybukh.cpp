#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char* name, char* content) {
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;
    if (!file) {
        file.close();
        return Failure;
    }

    file.close();
    return file.fail() ? Failure : Success;
}

int main() {
    char file_name[256];
    char content[1024];

    cout << "Введіть ім'я файла: ";
    cin >> file_name;
    cin.ignore(); // очищуєм буфер після зчитування ім'я файла

    cout << "Введіть вміст для запису у файл: ";
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(file_name, content);

    if (result == Success) {
        cout << "Дані успішно записані у файл." << endl;
    } else {
        cout << "Помилка запису у файл." << endl;
    }

    return 0;
}
