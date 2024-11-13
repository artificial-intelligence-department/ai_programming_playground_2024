#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (name == NULL || content == NULL) {
        cerr << "Неправильні вхідні дані: ім'я файлу або вміст є NULL." << endl;
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return Failure;
    }

    file << content;
    if (!file) {
        cerr << "Помилка під час запису у файл." << endl;
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    char filename[256];
    char content[256];

    cout << "Введіть ім'я файлу: ";
    cin.getline(filename, 256);

    cout << "Введіть вміст для запису: ";
    cin.getline(content, 256);

    FileOpResult result = write_to_file(filename, content);
    if (result == Success) {
        cout << "Вміст успішно записано у файл." << endl;
    } else {
        cout << "Не вдалося записати вміст у файл." << endl;
    }

    return 0;
}
