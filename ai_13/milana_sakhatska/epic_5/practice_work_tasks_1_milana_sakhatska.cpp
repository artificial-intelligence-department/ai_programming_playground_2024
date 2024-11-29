#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    ofstream file(name);
    
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл для запису.\n";
        return Failure;
    }
    
    file << content;
    
    if (!file) {
        cerr << "Помилка при записі у файл.\n";
        return Failure;
    }

    file.close();
    
    if (file.is_open()) {
        cerr << "Не вдалося закрити файл.\n";
        return Failure;
    }
    
    return Success;
}

int main() {
    char filename[100];
    char content[500];

    cout << "Введіть ім'я файлу: ";
    cin.getline(filename, 100);

    cout << "Введіть текст для запису у файл: ";
    cin.getline(content, 500);

    if (write_to_file(filename, content) == Success) {
        cout << "Текст успішно записано у файл.\n";
    } else {
        cout << "Не вдалося записати текст у файл.\n";
    }

    return 0;
}

