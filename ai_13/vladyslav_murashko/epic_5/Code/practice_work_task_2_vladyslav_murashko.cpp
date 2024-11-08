#include <iostream>
#include <fstream>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    if (file_from == nullptr || file_to == nullptr)
    {
        std::cout << "Error: Null file path provided.\n";
        return Failure;
    }

    std::ifstream src(file_from, std::ios::binary);
    if (!src.is_open())
    {
        std::cout << "Error: Cannot open source file \"" << file_from << "\"\n";
        return Failure;
    }

    std::ofstream dest(file_to, std::ios::binary);
    if (!dest.is_open())
    {
        std::cout << "Error: Cannot open destination file \"" << file_to << "\"\n";
        src.close();
        return Failure;
    }

    try
    {
        dest << src.rdbuf();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << "Error: File operation failed: " << e.what() << "\n";
        src.close();
        dest.close();
        return Failure;
    }

    src.close();
    dest.close();
    if (src.fail() || dest.fail())
    {
        std::cout << "Error: File closing failed.\n";
        return Failure;
    }

    return Success;
}

int main()
{
    char file_name_copy_form[256];
    char file_name_copy_to[256];

    std::cout << "Enter file name to copy from: ";
    std::cin.getline(file_name_copy_form, 256);

    std::cout << "Enter file name to copy to: ";
    std::cin.getline(file_name_copy_to, 256);

    FileOpResult result = copy_file(file_name_copy_form, file_name_copy_to);
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
