#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };


FileOpResult write_to_file(const char *name, const char *content) {
    if (name == NULL || content == NULL) {
        cout << "Неправильна назва файлу або вмісту!" << endl;
        return Failure;
    }

    ofstream file(name);

    if (!file.is_open()) {
        cout << "Не вдалось відкрити файл!" << endl;
        return Failure;
    }

    file << content;
    if (!file) {
        cout << "Помилка запису" << endl;
        file.close();
        return Failure;
    }

    file.close();
    if (file.fail()) {
        cout << "Помилка закриття файлу" << endl;
        return Failure;
    } else {
        return Success;
    }
}


FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (file_from == NULL || file_to == NULL) {
        cout << "Щось пішло не так!" << endl;
        return Failure;
    }

    ifstream file_in(file_from, ios::binary);
    if (!file_in.is_open()) {
        cout << "Не вдалось відкрити файл!" << endl;
        return Failure;
    }

    ofstream file_out(file_to, ios::binary);
    if (!file_out.is_open()) {
        cout << "Не вдалось створити файл!" << endl;
        return Failure;
    }

    file_out << file_in.rdbuf();

    if (!file_out) {
        cout << "Не вдалось записати файл!" << endl;
        return Failure;
    }

    file_in.close();
    file_out.close();
    return Success;
}

int main() {
    int choice;
    cout << "Оберіть операцію:\n1 - Записати у файл\n2 - Скопіювати файл\nВаш вибір: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        char filename[1024];
        char content[1024];

        cout << "Введіть назву файлу: ";
        cin.getline(filename, 1024);
        cout << "Введіть вміст для запису: ";
        cin.getline(content, 1024);

        FileOpResult result = write_to_file(filename, content);

        if (result == Success) {
            cout << "Все записано успішно!" << endl;
        } else {
            cout << "На жаль, не вдалось записати зміст! :(" << endl;
        }
    } else if (choice == 2) {
        char filein[1024];
        char fileout[1024];

        cout << "Введіть назву файлу-джерела: ";
        cin.getline(filein, 1024);
        cout << "Введіть назву файлу-призначення: ";
        cin.getline(fileout, 1024);

        FileOpResult finalresult = copy_file(filein, fileout);

        if (finalresult == Success) {
            cout << "Файл успішно скопійовано!" << endl;
        } else {
            cout << "На жаль, не вдалось скопіювати файл! :(" << endl;
        }
    } else {
        cout << "Неправильний вибір!" << endl;
    }

    return 0;
}
