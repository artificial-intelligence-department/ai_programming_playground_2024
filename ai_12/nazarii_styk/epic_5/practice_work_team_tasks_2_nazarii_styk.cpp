#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult CopyFile(const std::string& file_from, const std::string& file_to) 
{
    // Відкриваємо вхідний файл для читання
    std::ifstream inFile(file_from, std::ios::in | std::ios::binary);
    
    if (!inFile.is_open()) 
    {
        std::cerr << "Не вдалося відкрити файл для читання: " << file_from << std::endl;
        return Failure;
    }
    
    // Відкриваємо вихідний файл для запису
    std::ofstream outFile(file_to, std::ios::out | std::ios::binary);
    
    if (!outFile.is_open()) 
    {
        std::cerr << "Не вдалося відкрити файл для запису: " << file_to << std::endl;
        inFile.close(); 
        return Failure;
    }
    
    outFile << inFile.rdbuf(); 
    
    if (outFile.fail()) 
    {
        std::cerr << "Сталася помилка під час запису у файл: " << file_to << std::endl;
        inFile.close();
        outFile.close();
        return Failure;
    }

    inFile.close();
    outFile.close();
    
    return Success; 
}

int main() 
{
    std::string file_from, file_to;
    
    std::cout << "Введіть шлях до вхідного файлу: ";
    std::getline(std::cin, file_from);
    
    std::cout << "Введіть шлях до вихідного файлу: ";
    std::getline(std::cin, file_to);
    
    FileOpResult result = CopyFile(file_from, file_to);
    
    if (result == Success) 
    {
        std::cout << "Файл успішно скопійовано.\n";
    } 
    else 
    {
        std::cout << "Сталася помилка під час копіювання файлу.\n";
    }

    return 0;
}
