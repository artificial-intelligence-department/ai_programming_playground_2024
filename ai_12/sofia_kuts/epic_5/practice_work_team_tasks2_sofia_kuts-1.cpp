#include <iostream>
#include <fstream>

enum FileOpResult {
    Success,
    Failure
};

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure; // Перевірка на нульові вказівники
    }

    std::ifstream infile(file_from, std::ios::in | std::ios::binary); // Відкриття файла для читання
    if (!infile) {
        return Failure; // Не вдалося відкрити вхідний файл
    }

    std::ofstream outfile(file_to, std::ios::out | std::ios::binary | std::ios::trunc); // Відкриття файла для запису
    if (!outfile) {
        infile.close();
        return Failure; // Не вдалося відкрити вихідний файл
    }

    outfile << infile.rdbuf(); // Копіювання вмісту файлу

    if (!outfile.good() || !infile.good()) {
        infile.close();
        outfile.close();
        return Failure; // Перевірка на помилки при читанні/записі
    }

    infile.close();
    outfile.close();
    if (!outfile.good()) {
        return Failure; // Помилка при закритті файла
    }

    return Success;
}

int main() {
    std::string file_from, file_to;

    std::cout << "Enter the source filename: ";
    std::getline(std::cin, file_from);

    std::cout << "Enter the destination filename: ";
    std::getline(std::cin, file_to);

    FileOpResult result = copy_file(file_from.c_str(), file_to.c_str());
    if (result == Success) {
        std::cout << "File copied successfully.\n";
    } else {
        std::cout << "Failed to copy file.\n";
    }

    return 0;
}
