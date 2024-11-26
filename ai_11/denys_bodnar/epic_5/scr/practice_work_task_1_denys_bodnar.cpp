#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (!name || !content) {
        cerr << "Помилка: файл є порожнім" << endl;
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити або створити файл: " << name << endl;
        return Failure;
    }

    file << content;

    if (file.fail()) {
        cerr << "Помилка запису у файл: " << name << endl;
        return Failure;
    }

    file.close();
    if (file.fail()) {
        cerr << "Помилка закриття файлу: " << name << endl;
        return Failure;
    }

    return Success;
}

int main() {
    char fileName[256];
    char content[1024];

    cout << "Введіть ім'я файлу: ";
    cin.getline(fileName, 256);

    cout << "Введіть текст для запису у файл: ";
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(fileName, content);
    if (result == Success) {
        cout << "Вміст успішно записано у файл." << endl;
    } else {
        cerr << "Не вдалося записати вміст у файл." << endl;
    }

    return 0;
}
