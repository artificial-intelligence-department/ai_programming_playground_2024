#include <iostream>
#include <fstream>
#include <string>  

enum FileOpResult { Success, Failure };

FileOpResult WriteToFile(const std::string& name, const std::string& content) 
{
    // Перевірка на допустимість імені файлу та контенту
    if (name.empty() || content.empty()) 
    {
        return Failure; 
    }

    std::ofstream outFile(name);
    
    // Перевірка, чи файл відкрився успішно
    if (!outFile.is_open()) 
    {
        return Failure; 
    }

    outFile << content;
    
    // Перевірка на успішність запису
    if (outFile.fail()) 
    {
        outFile.close();
        return Failure;
    }

    outFile.close();
 
    return Success;
}

int main() 
{
    std::string filename;
    std::string content;
    
    std::cout << "Введіть ім'я файлу: ";
    std::getline(std::cin, filename);
    
    std::cout << "Введіть вміст, який потрібно записати у файл: ";
    std::getline(std::cin, content);

    FileOpResult result = WriteToFile(filename, content);
    
    if (result == Success) 
    {
        std::cout << "Файл успішно створений та записаний.\n";
    } 
    else 
    {
        std::cout << "Сталася помилка під час створення або запису файлу.\n";
    }

    return 0;
}
