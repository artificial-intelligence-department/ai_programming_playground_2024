#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
enum FileOpResult
{
    Succes,
    Failure
};

FileOpResult write_to_file(char *name, char *content);
FileOpResult copy_file(char *file_from, char *file_to);

int main()
{
    char name[100];
    std::cout << "Enter name of file: ";
    fgets(name, 100, stdin);
    char buf[200];
    std::cout << "Enter contents of the file: ";
    fgets(buf, 200, stdin);
    write_to_file(name, buf);

    char from[100];
    std::cout << "Enter file from which to copy: ";
    fgets(from, 100, stdin);
    char to[100];
    std::cout << "Enter file to which to copy: ";
    fgets(to, 100, stdin);
    copy_file(from, to);
    return 0;
}

FileOpResult write_to_file(char *name, char *content)
{
    name[strlen(name) - 1] = '\0';
    std::ofstream myFile(name);
    if (!myFile.is_open())
    {
        std::cerr << "cant open file" << '\n';
        return Failure;
    }
    myFile << content;
    myFile.close();
    if (myFile.is_open())
    {
        std::cerr << "cant close the file" << '\n';
        return Failure;
    }
    return Succes;
}

FileOpResult copy_file(char *file_from, char *file_to)
{
    file_from[strlen(file_from) - 1] = '\0';
    file_to[strlen(file_to) - 1] = '\0';
    std::ifstream from(file_from);
    std::ofstream to(file_to);
    if (!from.is_open())
    {
        std::cerr << "cant open 'from' file" << '\n';
        return Failure;
    }
    if (!to.is_open())
    {
        std::cerr << "cant open 'to' file" << '\n';
        return Failure;
    }
    std::string myText;
    while (getline(from, myText))
    {
        to << myText << '\n';
    }
    from.close();
    to.close();
    if (from.is_open())
    {
        std::cerr << "cant close 'from' file" << '\n';
        return Failure;
    }
    if (to.is_open())
    {
        std::cerr << "cant close 'to' file" << '\n';
        return Failure;
    }
    return Succes;
}
