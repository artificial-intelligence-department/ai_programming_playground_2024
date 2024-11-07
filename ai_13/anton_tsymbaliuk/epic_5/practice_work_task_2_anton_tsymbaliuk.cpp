#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure};

FileOpResult const copy_file(const char *file_from,const char *file_to){
    std::ifstream file1(file_from, std::ifstream::in);
    if(!file1) return Failure;
    std::fstream file2(file_to, std::fstream::out);
    if(!file2) return Failure;
    std::string line;
    while(std::getline(file1, line)){
        line += "\n";
        file2.write(line.c_str(), line.size());
    }
    file1.close();
    file2.close();
    return Success;
}


int main(){
    std::string file1, file2;
    std::cout << "Enter name of file to copy from(without extension): ";
    std::getline(std::cin, file1);
    std::cout << "Enter name of file in which to copy(without extension): ";
    std::getline(std::cin, file2);
    file1 += ".txt";
    file2 += ".txt";
    FileOpResult result = copy_file(file1.c_str(), file2.c_str());
    if(result == Success) std::cout << "Content was successfully copied\n";
    else std::cout << "Failed to copy files";
    return 0;
}