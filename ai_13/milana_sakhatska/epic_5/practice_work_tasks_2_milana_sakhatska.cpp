#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char* file_from, const char* file_to) {

    ifstream source(file_from, ios::binary);
    
    if (!source.is_open()) {
        cerr << "Не вдалося відкрити файл для читання: " << file_from << "\n";
        return Failure;
    }
    
    ofstream dest(file_to, ios::binary);
    
    if (!dest.is_open()) {
        cerr << "Не вдалося відкрити файл для запису: " << file_to << "\n";
        source.close();
        return Failure;
    }
    
    dest << source.rdbuf();
    
    if (!dest) {
        cerr << "Помилка при записі у файл.\n";
        source.close();
        dest.close();
        return Failure;
    }

    source.close();
    dest.close();

    return Success;
}

int main() {
    char file_from[100];
    char file_to[100];

    cout << "Введіть ім'я файлу, з якого копіювати: ";
    cin.getline(file_from, 100);

    cout << "Введіть ім'я файлу, куди копіювати: ";
    cin.getline(file_to, 100);

    if (copy_file(file_from, file_to) == Success) {
        cout << "Файл успішно скопійовано.\n";
    } else {
        cout << "Не вдалося скопіювати файл.\n";
    }

    return 0;
}
