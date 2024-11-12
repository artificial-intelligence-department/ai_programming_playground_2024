#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& name, const string& content) {
    if (name.empty() || content.empty()) {
        return Failure;
    }

    ofstream file(name, ios::out | ios::trunc);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;
    if (!file) {
        file.close();
        return Failure;
    }

    file.close();
    if (!file) {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const string& file_from, const string& file_to) {
    if (file_from.empty() || file_to.empty()) {
        return Failure;
    }

    ifstream src_file(file_from, ios::binary);
    if (!src_file.is_open()) {
        return Failure;
    }

    ofstream dest_file(file_to, ios::binary | ios::trunc);
    if (!dest_file.is_open()) {
        src_file.close();
        return Failure;
    }

    dest_file << src_file.rdbuf();

    if (!dest_file) {
        src_file.close();
        dest_file.close();
        return Failure;
    }

    src_file.close();
    dest_file.close();

    if (!src_file || !dest_file) {
        return Failure;
    }

    return Success;
}

int main() {
    string file_name, content, source_file, target_file;

    cout << "Введіть ім'я файлу для запису: ";
    getline(cin, file_name);

    cout << "Введіть вміст файлу для запису: ";
    getline(cin, content);

    FileOpResult write_result = write_to_file(file_name, content);

    if (write_result == Success) {
        cout << "Запис успішний." << endl;
    } else {
        cout << "Помилка запису." << endl;
    }


    cout << "Введіть ім'я файлу-джерела для копіювання: ";
    getline(cin, source_file);

    cout << "Введіть ім'я файлу-призначення для копіювання: ";
    getline(cin, target_file);

    FileOpResult copy_result = copy_file(source_file, target_file);

    if (copy_result == Success) {
        cout << "Копіювання успішне." << endl;
    } else {
        cout << "Помилка копіювання." << endl;
    }

    return 0;
}
  