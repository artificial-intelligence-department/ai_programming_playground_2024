#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (!name || !content) {
        cerr << "Error: Invalid input parameters." << endl;
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) {
        cerr << "Error: Failed to open the file." << endl;
        return Failure;
    }

    file << content;
    if (file.fail()) {
        cerr << "Error: Failed to write to the file." << endl;
        file.close();
        return Failure;
    }

    file.close();
    if (file.fail()) {
        cerr << "Error: Failed to close the file." << endl;
        return Failure;
    }

    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter the filename: ";
    cin.getline(filename, 256);

    cout << "Enter the content to write into the file: ";
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(filename, content);
    if (result == Success) {
        cout << "File written successfully." << endl;
    } else {
        cout << "File operation failed." << endl;
    }

    return 0;
}
