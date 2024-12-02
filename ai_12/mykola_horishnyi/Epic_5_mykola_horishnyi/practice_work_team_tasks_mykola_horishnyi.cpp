#include <iostream>
#include <cstdio>

using namespace std;

enum FileOpResult {
    Success, // Все пройшло успішно
    Failure  // Помилка при роботі з файлом
};

FileOpResult write_to_file(char* name, char* content) {
    // Відкриваємо файл для запису (перезаписуємо вміст, якщо файл існує)
    FILE* file = fopen(name, "w");

    // Перевіряємо, чи вдалося відкрити файл
    if (file == nullptr) {
        return Failure;  // Не вдалося відкрити файл
    }

    // Записуємо вміст у файл
    if (fprintf(file, "%s", content) < 0) {
        fclose(file);  // Закриваємо файл у разі помилки запису
        return Failure; // Помилка при записі
    }

    // Закриваємо файл після успішного запису
    if (fclose(file) != 0) {
        return Failure;  // Помилка при закритті файлу
    }

    return Success; // Операція завершена успішно
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter name of your file: ";
    cin >> filename; // Вводимо ім'я файлу

    cout << "Enter text which do you wanna to see insede: ";
    cin.ignore();  // Очищаємо буфер вводу
    cin.getline(content, 1024);  // Вводимо вміст

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "You createdd a file" << endl;
    }
    else {
        cout << "Error " << endl;
    }

    return 0;
}
