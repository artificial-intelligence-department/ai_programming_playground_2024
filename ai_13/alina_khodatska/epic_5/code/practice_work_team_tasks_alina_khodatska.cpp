#include <iostream>
#include <fstream>
#include <string>

// Оголошення перерахунку для результату операції
enum FileOpResult { Success, Failure };

// Функція для запису в файл
FileOpResult write_to_file(const char* name, const char* content) {
    // Перевірка вхідних параметрів
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    // Спроба відкрити файл для запису
    std::ofstream outfile(name);
    if (!outfile.is_open()) {
        return Failure;
    }

    // Запис вмісту в файл
    outfile << content;

    // Перевірка чи запис був успішним
    if (outfile.fail()) {
        return Failure;
    }

    // Закриття файлу
    outfile.close();

    // Перевірка чи файл був успішно закритий
    if (outfile.fail()) {
        return Failure;
    }

    return Success;
}

// Функція для копіювання вмісту з одного файлу в інший
FileOpResult copy_file(const char* file_from, const char* file_to) { 
    // file_from - відкриваємий файл, file_to - файл, в який копіюємо, const char* - вказівник на константний масив символів
    // Перевірка вхідних параметрів
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    // Спроба відкрити файл для читання
    std::ifstream infile(file_from, std::ios::binary);
    if (!infile.is_open()) {
        return Failure;
    }

    // Спроба відкрити файл для запису
    std::ofstream outfile(file_to, std::ios::binary);
    if (!outfile.is_open()) {
        infile.close();
        return Failure;
    }

    // Копіювання вмісту
	outfile << infile.rdbuf(); // rdbuf() - повертає вказівник на об'єкт, який містить вміст файлу

    // Перевірка чи запис був успішним
    if (outfile.fail() || infile.fail()) {
        infile.close();
        outfile.close();
        return Failure;
    }

    // Закриття файлів
    infile.close();
    outfile.close();

    // Перевірка чи файли були успішно закриті
    if (infile.fail() || outfile.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    // Запис у файл
    std::string filename;
    std::string content;

    std::cout << "Enter filename for write operation: ";
    std::getline(std::cin, filename);

    std::cout << "Enter content to write to the file: ";
    std::getline(std::cin, content);

	FileOpResult result = write_to_file(filename.c_str(), content.c_str()); 
	//filename.c_str() - повертає вказівник на масив символів, який містить ім'я файлу
    //content.c_str() - повертає вказівник на масив символів, який містить вміст файлу
    if (result == Success) {
        std::cout << "File written successfully." << std::endl;
    }
    else {
        std::cout << "Failed to write to file." << std::endl;
    }

    // Копіювання файлів
    std::string sourceFile;
    std::string destinationFile;

    std::cout << "\nEnter source filename for copy operation: ";
    std::getline(std::cin, sourceFile);

    std::cout << "Enter destination filename for copy operation: ";
    std::getline(std::cin, destinationFile);

    result = copy_file(sourceFile.c_str(), destinationFile.c_str()); 
	// sourceFile.c_str() - повертає вказівник на масив символів, який містить ім'я вихідного файлу 
    // destinationFile.c_str() - повертає вказівник на масив символів, який містить ім'я файлу, в який копіюємо
    if (result == Success) {
        std::cout << "File copied successfully." << std::endl;
    }
    else {
        std::cout << "Failed to copy file." << std::endl;
    }

    return 0;
}
