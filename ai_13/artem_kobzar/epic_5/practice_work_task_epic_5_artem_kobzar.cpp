#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Failure, Success };

FileOpResult write_to_file(char* name, char* content) {
    if (name == nullptr || strlen(name) == 0) {
        cout << "Cannot create file without a name" << endl;
        return Failure;
    }

    ofstream myFile(name);
    if (!myFile.is_open()) {
        cout << "Can't open file: " << name << endl;
        return Failure;
    }

    myFile << content << endl;
    if (myFile.fail()) {
        cout << "Error while writing data to file: " << name << endl;
        return Failure;
    }

    myFile.close();
    if (myFile.fail()) {
        cout << "Error closing file: " << name << endl;
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(char* file_from, char* file_to) {
    if (file_from == nullptr || file_to == nullptr || strlen(file_from) == 0 || strlen(file_to) == 0) {
        cout << "File names cannot be empty" << endl;
        return Failure;
    }

    ifstream inputFile(file_from);
    if (!inputFile.is_open()) {
        cout << "No such file: " << file_from << endl;
        return Failure;
    }

    ofstream outputFile(file_to);
    if (!outputFile.is_open()) {
        cout << "Can't open destination file: " << file_to << endl;
        inputFile.close();
        return Failure;
    }

    char buffer[256];
    while (inputFile.getline(buffer, sizeof(buffer))) {
        outputFile << buffer << endl;
        if (outputFile.fail()) {
            cout << "Error while writing to file: " << file_to << endl;
            inputFile.close();
            outputFile.close();
            return Failure;
        }
    }

    inputFile.close();
    outputFile.close();

    return Success;
}

int main() {
    char filename1[256], content[256];
    cout << "Enter the name of the file: ";
    cin.getline(filename1, sizeof(filename1));

    cout << "Enter content for the file: ";
    cin.getline(content, sizeof(content));

    if (write_to_file(filename1, content) == Success) {
        cout << "File written successfully!" << endl;
    } else {
        cout << "Failed to write to file." << endl;
        return 1;
    }

    char filename2[256];
    cout << "Enter the name of the file to copy to: ";
    cin.getline(filename2, sizeof(filename2));

    if (copy_file(filename1, filename2) == Success) {
        cout << "File copied successfully!" << endl;
    } else {
        cout << "Failed to copy the file." << endl;
        return 1;
    }

    return 0;
}
