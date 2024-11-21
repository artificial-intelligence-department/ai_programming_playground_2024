#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult
{
    Success,
    Failure
};
FileOpResult copy_file(char *file_from, char *file_to)
{
    if (file_from==nullptr || file_to==nullptr)
    {
        std::cout << "There is either no file 1 or no file 2." << std::endl;
        return Failure;
    }
    std::ifstream file1(file_from, std::ios::binary);
    if(file1.fail())
    {
        std::cout << "Failed to open file 1." << std::endl;
        return Failure;
    }
    std::ofstream file2(file_to, std::ios::binary);
    if(file2.fail())
    {
        std::cout << "Failed to open file 2.";
        file1.close();
        return Failure;
    }
    file2 << file1.rdbuf();
    file1.close();
    if(file1.fail())
    {
        std::cout << "Something went wrong while copying from file 1." << std::endl;
        return Failure;
    }
    file2.close();
    if(file1.fail())
    {
        std::cout << "Something went wrong while copying to file 2." << std::endl;
        return Failure;
    }
    return Success;
}

int main()
{
    char name1[50];
    char name2[50];
    std::cout << "Enter the name of file 1: ";
    std::cin.getline(name1, 50);
    std::cout << "Enter the name of file 2: ";
    std::cin.getline(name2, 50);
    FileOpResult what_happened = copy_file(name1, name2);
    if(what_happened == Success)
    {
        std::cout << "Copied successfully.";
    }
    else
    {
        std::cout << "Failed to copy.";
    }
}