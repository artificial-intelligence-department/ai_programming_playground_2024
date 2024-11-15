#include <iostream>
#include <fstream>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content)
{
    if (name == nullptr || content == nullptr)
    {
        std::cout << "Error: Null file name or content provided.\n";
        return Failure;
    }

    std::ofstream file(name);
    if (!file.is_open())
    {
        std::cout << "Error: Cannot open file \"" << name << "\" for writing.\n";
        return Failure;
    }

    try
    {
        file << content;
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << "Error: File writing failed: " << e.what() << "\n";
        file.close();
        return Failure;
    }

    file.close();
    if (file.fail())
    {
        std::cout << "Error: File closing failed.\n";
        return Failure;
    }

    return Success;
}

int main()
{
    char file_name_write[256];
    char content[1024];

    std::cout << "Enter file name: ";
    std::cin.getline(file_name_write, 256);

    std::cout << "Enter content to write: ";
    std::cin.getline(content, 1024);

    FileOpResult result = write_to_file(file_name_write, content);
    if (result == Success)
    {
        std::cout << "File written successfully.\n";
    }
    else
    {
        std::cout << "Failed to write to file.\n";
    }

    return 0;
}
