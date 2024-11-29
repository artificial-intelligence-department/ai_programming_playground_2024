#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    std::ofstream file(name, std::ios::out | std::ios::trunc);  // Відкриваємо файл у режимі перезапису
    if (!file.is_open()) {
        return Failure;
    }

    file << content; 
    if (file.fail()) {
        return Failure;
    }

    file.close();
    return file.fail() ? Failure : Success;
}

int main() {
    std::string filename;
    std::string content;

    std::cout << "Введіть ім'я файлу: ";
    std::getline(std::cin, filename);  

    std::cout << "Введіть вміст файлу: ";
    std::getline(std::cin, content);  

    FileOpResult result = write_to_file(filename.c_str(), content.c_str());

    if (result == Success) {
        std::cout << "Запис успішний!" << std::endl;
    } else {
        std::cout << "Помилка запису!" << std::endl;
    }

    return 0;
}
