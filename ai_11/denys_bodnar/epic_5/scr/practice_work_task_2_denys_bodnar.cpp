#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (!file_from || !file_to) {
        cerr << "Помилка: вихідне або цільове ім'я файлу є порожнім." << endl;
        return Failure;
    }

    ifstream src(file_from, ios::binary);
    if (!src.is_open()) {
        cerr << "Не вдалося відкрити вихідний файл: " << file_from << endl;
        return Failure;
    }

    ofstream dest(file_to, ios::binary);
    if (!dest.is_open()) {
        cerr << "Не вдалося відкрити або створити цільовий файл: " << file_to << endl;
        src.close();
        return Failure;
    }

    dest << src.rdbuf(); // Ефективне копіювання всього вмісту

    if (dest.fail() || src.fail()) {
        cerr << "Сталася помилка під час копіювання файлу." << endl;
        src.close();
        dest.close();
        return Failure;
    }

    src.close();
    dest.close();

    if (src.fail() || dest.fail()) {
        cerr << "Сталася помилка під час закриття файлів." << endl;
        return Failure;
    }

    return Success;
}

int main() {
    char sourceFile[256];
    char destinationFile[256];

    cout << "Введіть ім'я вихідного файлу: ";
    cin.getline(sourceFile, 256);

    cout << "Введіть ім'я цільового файлу: ";
    cin.getline(destinationFile, 256);

    FileOpResult result = copy_file(sourceFile, destinationFile);
    if (result == Success) {
        cout << "Файл успішно скопійовано." << endl;
    } else {
        cerr << "Не вдалося скопіювати файл." << endl;
    }

    return 0;
}
