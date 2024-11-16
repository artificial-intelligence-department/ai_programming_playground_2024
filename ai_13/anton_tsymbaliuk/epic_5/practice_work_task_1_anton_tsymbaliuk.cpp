#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

enum FileOpResult { Failure, Success };

FileOpResult const write_to_file(const char *name,const char *content){
    std::fstream file(name, std::fstream::out);
    if(!file) return Failure;
    file.write(content, strlen(content));
    file.close();
    return Success;
}

int main(){
    std::string name;
    std::string content;
    std::cout << "Enter file name(without extension): ";
    getline(std::cin, name);            //works without <string> but becomes highlighted
    name += ".txt";
    std::cout << "Enter file content: ";
    std::getline(std::cin, content);

    FileOpResult result = write_to_file(name.c_str(), content.c_str());
    if(result == Success) std::cout << "File was successfully rewrited\n";
    else std::cout << "Failed to rewrite a file";
    return 0;
}