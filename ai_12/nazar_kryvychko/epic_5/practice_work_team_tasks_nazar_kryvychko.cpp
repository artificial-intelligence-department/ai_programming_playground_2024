#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <string>

enum FileOpResult { Success = 0, Failure = 1 };

static std::map<FileOpResult, std::string> OperationStr = { 
    { Success, "Success" },
    { Failure, "Failure" }
};

bool hasEnding(const std::string& fullString, const std::string& ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

FileOpResult write_to_file(const char* name, const char* content) {
    if (name == nullptr || strcmp(name, "") == 0 || !hasEnding(name, ".txt")) {
        name = "default.txt";
    }

    std::ofstream fileOut(name, std::ios::out | std::ios::trunc);
    if (!fileOut.is_open()) {
        return FileOpResult::Failure;
    }

    fileOut << content;
    if (!fileOut.good()) { // Check if writing to file was successful
        return FileOpResult::Failure;
    }

    fileOut.close();
    return fileOut.fail() ? FileOpResult::Failure : FileOpResult::Success;
}

unsigned int FileRead(std::istream& is, std::vector<char>& buff) {
    is.read(&buff[0], buff.size());
    return is.gcount();
}

void FileRead(std::ifstream& ifs, std::string& s) {
    const unsigned int BUFSIZE = 64 * 1024;
    std::vector<char> buffer(BUFSIZE);

    while (unsigned int n = FileRead(ifs, buffer)) {
        s.append(&buffer[0], n);
    }
}

FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (file_from == nullptr || strcmp(file_from, "") == 0 ||
        file_to == nullptr || strcmp(file_to, "") == 0 ||
        !hasEnding(file_from, ".txt") || !hasEnding(file_to, ".txt")) {
        return FileOpResult::Failure;
    }

    std::ifstream fileIn(file_from, std::ios::in);
    if (!fileIn.is_open()) {
        return FileOpResult::Failure;
    }

    std::ofstream fileOut(file_to, std::ios::out | std::ios::trunc);
    if (!fileOut.is_open()) {
        fileIn.close();
        return FileOpResult::Failure;
    }

    std::string fileContent;
    FileRead(fileIn, fileContent);
    fileOut << fileContent;

    bool failure = fileIn.bad() || fileOut.bad();
    fileIn.close();
    fileOut.close();

    return failure ? FileOpResult::Failure : FileOpResult::Success;
}

int main() {
    // Task [1]
    std::string contentLine, fileName;
    std::cout << "Enter content: ";
    std::getline(std::cin, contentLine);
    std::cout << "Enter file name: (*.txt) (DEFAULT NAME = \"default.txt\"): ";
    std::getline(std::cin, fileName);
    FileOpResult writeResult = write_to_file(fileName.c_str(), contentLine.c_str());
    std::cout << "Operation Result: " << OperationStr[writeResult] << std::endl;

    // Task [2]
    std::string fromFile, toFile;
    std::cout << "Enter file name {from}: ";
    std::getline(std::cin, fromFile);
    std::cout << "Enter file name {to}: ";
    std::getline(std::cin, toFile);
    FileOpResult copyResult = copy_file(fromFile.c_str(), toFile.c_str());
    std::cout << "Copy Operation Result: " << OperationStr[copyResult] << std::endl;

    return 0;
}
