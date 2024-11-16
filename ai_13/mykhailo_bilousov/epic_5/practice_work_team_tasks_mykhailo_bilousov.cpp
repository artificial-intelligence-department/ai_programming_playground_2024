#include <iostream>
#include <fstream>
#include <cstring>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(const char* path, const char* content)
{
    std::fstream fs;
    fs.open(path, std::fstream::out | std::fstream::binary | std::fstream::trunc);
    if (!fs) 
    {
        return FileOpResult::Failure;
    }
    
    fs.write(content, strlen(content));

    delete[] content;
    fs.close();
    return FileOpResult::Success;
}

FileOpResult copy_file(const char* src_path, const char* dest_path)
{
    std::fstream src_fs;
    src_fs.open(src_path, std::fstream::in | std::fstream::binary | std::fstream::ate);
    if (!src_fs) 
    {
        return FileOpResult::Failure;
    }
    int size = src_fs.tellg();
    src_fs.seekg(0);
    char* content = new char[size];
    src_fs.read(content, size);
    src_fs.close();


    std::fstream dest_fs;
    dest_fs.open(dest_path, std::fstream::out | std::fstream::binary | std::fstream::trunc);
    if (!dest_fs) 
    {
        delete[] content;
        return FileOpResult::Failure;
    }
    dest_fs.write(content, size);

    delete[] content;
    dest_fs.close();
    return FileOpResult::Success;
}

int main()
{
    char* content = new char[BUFSIZ];
    std::cin >> content;
    if(write_to_file("practice.txt", content) == FileOpResult::Failure) 
        std::cout << "Error writing to practice.txt\n";
    if(write_to_file("/root/practice.txt", content) == FileOpResult::Failure) 
        std::cout << "Error writing to /root/practice.txt\n"; // expected
    if(copy_file("practice.txt", "practice1.txt") == FileOpResult::Failure) 
        std::cout << "Error copying to practice1.txt\n";
    if(copy_file("practice.txt", "/root/practice1.txt") == FileOpResult::Failure) 
        std::cout << "Error copying to /root/practice1.txt\n"; // expected
}