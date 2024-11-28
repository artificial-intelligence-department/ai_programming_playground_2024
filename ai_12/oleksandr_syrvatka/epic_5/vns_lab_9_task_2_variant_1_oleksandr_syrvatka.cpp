#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// Функція для створення файлу F1 з 10 рядками
void createFileF1(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // Записуємо 10 рядків у файл F1
    for (int i = 1; i <= 10; ++i) {
        fprintf(file, "This is line number %d\n", i);
    }

    fclose(file);
    cout << "File F1 created with 10 lines." << endl;
}

// Функція для копіювання парних рядків з F1 у F2
void copyEvenLines(const char* inputFile, const char* outputFile) {
    FILE* inFile = fopen(inputFile, "r");
    FILE* outFile = fopen(outputFile, "w");
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        fclose(inFile);
        return;
    }

    char line[256];  // Буфер для зчитування рядків
    int lineNumber = 1;

    // Читання і запис кожного рядка з F1
    while (fgets(line, sizeof(line), inFile)) {
        if (lineNumber % 2 == 0) {
            fputs(line, outFile);  // Записуємо парний рядок у F2
        }
        lineNumber++;
    }

    fclose(inFile);
    fclose(outFile);
    cout << "Even lines copied to file F2." << endl;
}

// Функція для підрахунку розміру файлу
size_t getFileSize(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return 0;
    }

    fseek(file, 0, SEEK_END);  // Переходимо в кінець файлу
    size_t size = ftell(file); // Отримуємо розмір файлу
    fclose(file);

    return size;
}

// Функція для друку вмісту файлу
void printFileContents(const char* filename) {
    FILE* file = fopen(filename, "r");  // Відкриваємо файл для читання
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    char line[256];  // Масив для зберігання рядка

    // Читаємо файл рядок за рядком
    while (fgets(line, sizeof(line), file)) {
        cout << line;  // Виводимо кожен рядок
    }

    fclose(file);  // Закриваємо файл після завершення роботи з ним
}

int main() {
    const char* fileF1 = "F1.txt";
    const char* fileF2 = "F2.txt";

    // Створюємо файл F1 з 10 рядками
    createFileF1(fileF1);

    // Копіюємо парні рядки з F1 у F2
    copyEvenLines(fileF1, fileF2);

    // Виводимо розміри файлів F1 та F2
    size_t sizeF1 = getFileSize(fileF1);
    size_t sizeF2 = getFileSize(fileF2);

    cout << "Розмір файлу Ф1: " << sizeF1 << " байт" << endl;
    cout << "Розмір файлу Ф2: " << sizeF2 << " байт" << endl;

    cout << "Вміст файлу 1:";
    printFileContents(fileF1);
    cout << "Вміст файлу 2:";
    printFileContents(fileF2);

    return 0;
}
