#include <iostream>
#include <cstring>
#include <fstream>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content)
{
    if (strlen(name) == 0)
    {
        std::cerr << "Error: File name cannot be empty.\n";
        return Failure;
    }

    std::ofstream file(name);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create or open the file \"" << name << "\"\n";
        return Failure;
    }

    try
    {
        file << content;
    }
    catch (const std::ios_base::failure &err)
    {
        std::cerr << "Error: File writing failed: " << err.what() << "\n";
        file.close();
        return Failure;
    }

    file.close();
    if (file.fail())
    {
        std::cerr << "Error: File closing failed.\n";
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    if (strlen(file_from) == 0 || strlen(file_to) == 0)
    {
        std::cerr << "Error: No file name or path provided.\n";
        return Failure;
    }

    std::ifstream source(file_from, std::ios::binary);
    if (!source.is_open())
    {
        std::cerr << "Error: Cannot open source file \"" << file_from << "\"\n";
        return Failure;
    }

    std::ofstream destination(file_to, std::ios::binary);
    if (!destination.is_open())
    {
        std::cerr << "Error: Cannot open destination file \"" << file_to << "\"\n";
        source.close();
        return Failure;
    }

    try
    {
        destination << source.rdbuf();
    }
    catch (const std::ios_base::failure &err)
    {
        std::cerr << "Error: File operation failed: " << err.what() << "\n";
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();

    if (source.fail() || destination.fail())
    {
        std::cerr << "Error: File closing failed.\n";
        return Failure;
    }

    return Success;
}

int main()
{
    /*---------- TASK 1: Write to File ----------*/
    char file_name_to_write[256];
    char content[1024];

    std::cout << "Enter file name: ";
    std::cin.getline(file_name_to_write, 256);

    std::cout << "Enter content to write: ";
    std::cin.getline(content, 1024);

    FileOpResult result = write_to_file(file_name_to_write, content);
    if (result == Success)
    {
        std::cout << "Wrote to the file successfully.\n";
    }
    else
    {
        std::cout << "Failed to write to the file.\n";
    }

    /*---------- TASK 2: Copy File ----------*/
    char file_name_copy_from[256];
    char file_name_copy_to[256];

    std::cout << "Enter file name to copy from: ";
    std::cin.getline(file_name_copy_from, 256);

    std::cout << "Enter file name to copy to: ";
    std::cin.getline(file_name_copy_to, 256);

    result = copy_file(file_name_copy_from, file_name_copy_to);
    if (result == Success)
    {
        std::cout << "File data copied successfully.\n";
    }
    else
    {
        std::cout << "Failed to copy the file data.\n";
    }

    return 0;
}
