#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(char *name, char *content)
{
    if (name==nullptr || content==nullptr)
    {
        std::cout << "There is no file name." << std::endl;
        return Failure;
    }
    std::ofstream theFile(name);
    if(theFile.is_open())
    {
        theFile << content << std::endl;
        if(theFile.fail())
        {
            std::cout << "Something went wrong while writing content to the file." << std::endl;
            return Failure;
        }
        theFile.close();
        if(theFile.fail())
        {
            std::cout << "Something went wrong while closing the file." << std::endl;
            return Failure;
        }
    }
    else
    {
        std::cout << "Cannot open file." << std::endl;
        return Failure;
    }
    return Success;
}

int main()
{
    char name[50];
    char content[1000];
    std::cout << "Enter the name of the file: ";
    std::cin.getline(name, 50);
    std::cout << "Now enter the content of the file: ";
    std::cin.getline(content, 1000);
    FileOpResult what_happened = write_to_file(name, content);
    if(what_happened == Success)
    {
        std::cout << "File created successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to create a file." << std::endl;
    }
}