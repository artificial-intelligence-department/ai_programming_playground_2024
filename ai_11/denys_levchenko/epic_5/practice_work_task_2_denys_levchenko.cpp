#include <fstream>
#include <iostream>
#include <string>

using namespace std;
enum FileOpResult {
    Success,
    Failure
};

FileOpResult copy_file(const char* file_from, const char* file_to) {
    ifstream input(file_from, ios::binary);
    if (!input.is_open()) {
        cerr << "Помилка: Не вдалося відкрити вхідний файл " << file_from << "\n";
        return Failure;
    }

    ofstream output(file_to, ios::binary);
    if (!output.is_open()) {
        cerr << "Помилка: Не вдалося відкрити або створити вихідний файл " << file_to << "\n";
        input.close();
        return Failure;
    }

    output << input.rdbuf();

    if (!output) {
        cerr << "Помилка: Не вдалося записати дані у файл " << file_to << "\n";
        input.close();
        output.close();
        return Failure;
    }

    input.close();
    output.close();

    return Success;
}

int main() {
    const char* source = "otsuda.txt";
    const char* destination = "suda.txt";

    FileOpResult result = copy_file(source, destination);
    if (result == Success) {
        cout << "Файл успішно скопійовано!\n";
    } else {
        cout << "Помилка під час копіювання файлу.\n";
    }

    return 0;
}
