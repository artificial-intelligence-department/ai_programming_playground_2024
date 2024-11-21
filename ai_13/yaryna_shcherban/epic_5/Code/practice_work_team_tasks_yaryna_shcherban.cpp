#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Failure, Success };

FileOpResult write_to_file(const string& name, const string& content) {
    if (name.empty()) {
        cout << "Cannot create file without name" << endl;
        return Failure;
    }
    
    ofstream myFile(name);
    if (myFile.is_open()) {
        myFile << content << endl;
        if (myFile.fail()) {
            cout << "Error while writing data" << endl;
            return Failure;
        }
        myFile.close();
        if (myFile.fail()) {
            cout << "Error closing file" << endl;
            return Failure;
        }
    } else {
        cout << "Can't open file" << endl;
        return Failure;
    }
    return Success;
}

FileOpResult copy_file(const string& file_from, const string& file_to) {
    if (file_from.empty() || file_to.empty()) {
        cout << "Cannot create file without name" << endl;
        return Failure;
    }

    ifstream sourceFile(file_from);
    if (sourceFile.is_open()) {
        string line;
        while (getline(sourceFile, line)) {
            if (!write_to_file(file_to, line)) {
                return Failure;
            }
        }
        sourceFile.close();
    } else {
        cout << "Not such file" << endl;
        return Failure;
    }
    return Success;
}

int main() {
    string filename1, content;

    cout << "Enter name of file: " << endl;
    getline(cin, filename1);
    cout << "Enter content for file: " << endl;
    getline(cin, content);

    if (write_to_file(filename1, content) == Success) {
        cout << "File created successfully." << endl;
    } else {
        cout << "Failed to create file." << endl;
        return 0;
    }

    string filename2;
    cout << "Enter name of file to copy: " << endl;
    getline(cin, filename2);

    if (copy_file(filename1, filename2) == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "Failed to copy file." << endl;
        return 0;
    }

    return 0;
}