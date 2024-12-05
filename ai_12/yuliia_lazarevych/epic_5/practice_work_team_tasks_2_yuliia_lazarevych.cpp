#include <iostream>
#include <fstream>

using namespace std;

//перелік статусів операцій із файлами
enum FileOpResult { Success, Failure, InvalidInput };

//використовую функцію копіювання вмісту з одного файла в інший
FileOpResult copy_file(const char *file_from, const char *file_to) {
    //перевіряю вхідних параметрів
    if (file_from == nullptr || file_to == nullptr || *file_from == '\0' || *file_to == '\0') {
        cerr << "Помилка: Недійсні вхідні параметри.\n";
        return InvalidInput;
    }

    //відкриваю файл для читання
    ifstream source(file_from, ios::in | ios::binary);
    if (!source) {
        cerr << "Помилка: Не вдалося відкрити файл для читання: " << file_from << "\n";
        return Failure;
    }

    //відкриваю файл для запису
    ofstream destination(file_to, ios::out | ios::binary | ios::trunc);
    if (!destination) {
        cerr << "Помилка: Не вдалося створити або відкрити файл для запису: " << file_to << "\n";
        return Failure;
    }

    //копіюю вміст
    destination << source.rdbuf();
    if (!destination) {
        cerr << "Помилка: Не вдалося записати дані у файл.\n";
        return Failure;
    }

    //закриваю файл
    source.close();
    if (!source) {
        cerr << "Помилка: Не вдалося коректно закрити вхідний файл.\n";
        return Failure;
    }

    destination.close();
    if (!destination) {
        cerr << "Помилка: Не вдалося коректно закрити вихідний файл.\n";
        return Failure;
    }

    return Success;
}

int main() {
    char fileFrom[256], fileTo[256];

    cout << "Введіть ім'я файлу для копіювання (file_from): ";
    cin.getline(fileFrom, sizeof(fileFrom));

    cout << "Введіть ім'я файлу призначення (file_to): ";
    cin.getline(fileTo, sizeof(fileTo));

    //викликаю функцію копіювання
    FileOpResult result = copy_file(fileFrom, fileTo);

    if (result == Success) {
        cout << "Файл успішно скопійовано.\n";
    } else {
        cout << "Сталася помилка під час копіювання файлу.\n";
    }

    return 0;
}
