#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        return Failure; // Перевірка на нульові вказівники
    }

    std::ofstream outfile(name, std::ios::out | std::ios::trunc); // Відкриття файла для запису з перезаписом
    if (!outfile) {
        return Failure; // Не вдалося відкрити файл
    }

    outfile << content; // Запис вмісту в файл
    if (!outfile.good()) {
        return Failure; // Перевірка на помилки запису
    }

    outfile.close(); // Закриття файла
    if (!outfile.good()) {
        return Failure; // Помилка при закритті файла
    }

    return Success;
}

int main() {
    std::string filename, content;

    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    std::cout << "Enter the content to write: ";
    std::getline(std::cin, content);

    FileOpResult result = write_to_file(filename.c_str(), content.c_str());
    if (result == Success) {
        std::cout << "File written successfully.\n";
    } else {
        std::cout << "Failed to write to file.\n";
    }

    return 0;
}
