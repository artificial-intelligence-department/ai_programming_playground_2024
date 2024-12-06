#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    ofstream outFile(name);
    
    if (!outFile.is_open()) {
        return Failure;
    }

    outFile << content;

    if (outFile.fail()) {
        outFile.close();
        return Failure;
    }

    outFile.close();

    if (outFile.fail()) {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream inFile(file_from);
    
    if (!inFile.is_open()) {
        return Failure;
    }

    ofstream outFile(file_to);
    
    if (!outFile.is_open()) {
        inFile.close();
        return Failure;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    if (inFile.fail() || outFile.fail()) {
        inFile.close();
        outFile.close();
        return Failure;
    }

    inFile.close();
    outFile.close();

    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter filename to write: ";
    cin.getline(filename, 256);

    cout << "Enter content to write into the file: ";
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "File successfully created and content written!" << endl;
    } else {
        cout << "Error while creating or writing to the file." << endl;
    }

    char sourceFile[256], destFile[256];
    
    cout << "\nEnter source filename to copy from: ";
    cin.getline(sourceFile, 256);

    cout << "Enter destination filename to copy to: ";
    cin.getline(destFile, 256);

    result = copy_file(sourceFile, destFile);

    if (result == Success) {
        cout << "File successfully copied!" << endl;
    } else {
        cout << "Error while copying the file." << endl;
    }

    return 0;
}
