#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr || strlen(name) == 0) {
        cerr << "Invalid parameters.\n";
        return Failure;
    }

    ofstream file(name, ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << name << "\n";
        return Failure;
    }

    file << content;

    if (file.fail()) {
        cerr << "Error: Failed to write to file: " << name << "\n";
        file.close();
        return Failure;
    }

    file.close();
    if (file.fail()) {
        cerr << "Error: Failed to close the file: " << name << "\n";
        return Failure;
    }

    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter the file name: ";
    cin.getline(filename, sizeof(filename));

    cout << "Enter the content to write into the file: ";
    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file(filename, content);
    if (result == Success) {
        cout << "File written successfully.\n";
    } else {
        cerr << "File operation failed.\n";
    }

    return 0;
}
