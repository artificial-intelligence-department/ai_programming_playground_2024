#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Перелік статусів операцій з файлами
enum FileOpResult { Success, Failure, InvalidInput, WriteError, CloseError };

//використовую функцію для роботи з текстовими файлами
FileOpResult write_to_file(const char *name, const char *content) {
    //використовую перевірку вхідних параметрів для стійкості до різних вхідних даних
    if (name == nullptr || content == nullptr || *name == '\0') {
        cerr << "Помилка: Недійсні вхідні дані.\n";
        return InvalidInput;
    }

    //відкриваю файлу для запису в текстовий файл
    ofstream file(name, ios::out | ios::trunc);
    if (!file) {
        cerr << "Помилка: Не вдалося створити або відкрити файл.\n";
        return Failure;
    }

    //записую вмісту у файл
    file << content;
    if (!file) {
        cerr << "Помилка: Не вдалося записати дані у файл.\n";
        return WriteError;
    }

    //закриваю файлу
    file.close();
    if (!file) {
        cerr << "Помилка: Не вдалося коректно закрити файл.\n";
        return CloseError;
    }

    return Success;
}

//використовую функцію для роботи з бінарними файлами
FileOpResult write_binary_file(const char *name, const char *data, size_t size) {
    //перевіряю вхідні параметри для стійкості до різних вхідних даних
    if (name == nullptr || data == nullptr || *name == '\0') {
        cerr << "Помилка: Недійсні вхідні дані.\n";
        return InvalidInput;
    }

    //відкриваю файл для запису в бінарний файл
    ofstream file(name, ios::out | ios::binary | ios::trunc);
    if (!file) {
        cerr << "Помилка: Не вдалося створити або відкрити файл.\n";
        return Failure;
    }

    //записую бінарний вміст у файл
    file.write(data, size);
    if (!file) {
        cerr << "Помилка: Не вдалося записати дані у файл.\n";
        return WriteError;
    }

    //закриваю файл
    file.close();
    if (!file) {
        cerr << "Помилка: Не вдалося коректно закрити файл.\n";
        return CloseError;
    }

    return Success;
}

int main() {
    //робота з текстовими файлами
    char fileName[256];
    string content;

    cout << "Введіть ім'я текстового файлу: ";
    cin.getline(fileName, sizeof(fileName));

    cout << "Введіть вміст для запису у текстовий файл: ";
    getline(cin, content);

    //записую у текстовий файл
    FileOpResult result = write_to_file(fileName, content.c_str());
    if (result == Success) {
        cout << "Текстовий файл успішно записаний.\n";
    } else {
        cout << "Помилка при роботі з текстовим файлом.\n";
    }

    //робота з бінарними файлами
    cout << "Введіть ім'я бінарного файлу: ";
    cin.getline(fileName, sizeof(fileName));

    char binaryData[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t binarySize = sizeof(binaryData);

    //записую у бінарний файл
    result = write_binary_file(fileName, binaryData, binarySize);
    if (result == Success) {
        cout << "Бінарний файл успішно записаний.\n";
    } else {
        cout << "Помилка при роботі з бінарним файлом.\n";
    }

    return 0;
}
