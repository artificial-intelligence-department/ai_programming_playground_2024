#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    ofstream file(name);

    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        return Failure;
    }

    file.close();

    if (file.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    char filename[100], content[500];

    cout << "Enter the filename: ";
    cin.getline(filename, 100);

    cout << "Enter the content to write to the file: ";
    cin.getline(content, 500);

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "File written successfully!" << endl;
    }
    else {
        cout << "Error writing file!" << endl;
    }

    return 0;
}
