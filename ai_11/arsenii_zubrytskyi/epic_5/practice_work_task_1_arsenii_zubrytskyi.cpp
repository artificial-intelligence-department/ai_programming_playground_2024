#include <iostream>
#include <fstream>
#include <sstream>

enum FileOpResult { Success, Failure };

// Функція запису тексту у файл
FileOpResult write_to_file(const char* name, const char* content) {
    std::ofstream outFile(name, std::ios::trunc);  // Відкриваємо файл для запису
    if (!outFile) {
        std::cerr << "Не вдалося відкрити файл для запису!" << std::endl;
        return Failure;  // Якщо файл не відкрився для запису
    }
    outFile << content;
    if (outFile.fail()) {
        std::cerr << "Помилка при записі в файл!" << std::endl;
        return Failure;  // Помилка при записі
    }
    outFile.close();  // Закриваємо файл
    return Success;
}

// Функція копіювання вмісту одного файлу в інший
FileOpResult copy_file(const char* file_from, const char* file_to) {
    std::ifstream inFile(file_from, std::ios::binary);  // Відкриваємо файл для читання в бінарному режимі
    if (!inFile) {
        std::cerr << "Не вдалося відкрити вхідний файл для читання!" << std::endl;
        return Failure;  // Якщо файл не відкрився для читання
    }

    std::ofstream outFile(file_to, std::ios::binary);  // Відкриваємо файл для запису в бінарному режимі
    if (!outFile) {
        std::cerr << "Не вдалося відкрити вихідний файл для запису!" << std::endl;
        return Failure;  // Якщо файл не відкрився для запису
    }

    // Буфер для читання з файлу та запису
    const size_t bufferSize = 1024;
    char buffer[bufferSize];

    // Читання з вхідного файлу та запис у вихідний
    while (inFile.read(buffer, bufferSize) || inFile.gcount() > 0) {
        outFile.write(buffer, inFile.gcount());
        if (outFile.fail()) {
            std::cerr << "Помилка при записі в вихідний файл!" << std::endl;
            return Failure;  // Помилка при записі
        }
    }

    inFile.close();  // Закриваємо вхідний файл
    outFile.close();  // Закриваємо вихідний файл
    return Success;
}

int main() {
    // Задача 1: Запис в файл
    const char* filename = "output.txt";
    const char* content = "Це текст, який потрібно записати у файл.";
    if (write_to_file(filename, content) == Success)
        std::cout << "Текст успішно записано в файл!" << std::endl;
    else
        std::cout << "Не вдалося записати текст у файл." << std::endl;

    // Задача 2: Копіювання вмісту одного файлу в інший
    const char* file_from = "input.txt";
    const char* file_to = "copied_output.txt";

    // Перевірка, чи існує вхідний файл
    std::ifstream checkFile(file_from);
    if (!checkFile) {
        std::cout << "Файл для копіювання не існує!" << std::endl;
        return Failure;
    }

    if (copy_file(file_from, file_to) == Success)
        std::cout << "Вміст успішно скопійовано!" << std::endl;
    else
        std::cout << "Не вдалося скопіювати вміст файлів." << std::endl;

    return 0;
}
