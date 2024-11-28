#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class FileOpResult {
    Success, 
    Failure   
};

FileOpResult write_to_file(const char *name, const string content[], int quantity_of_lines) {
    if (name == nullptr || quantity_of_lines <= 0) {
        cerr << "Error: Invalid arguments provided.\n";
        return FileOpResult::Failure;
    }

    ofstream file(name, ios::out | ios::trunc);
    if (!file) {
        cerr << "Error: Unable to open file for writing.\n";
        return FileOpResult::Failure;
    }

    for(int i = 0; i < quantity_of_lines; i++){
    file << content[i] << endl;

        if (!file) {
            cerr << "Error: Write operation failed on line " << i + 1 << ".\n";
            file.close();
            return FileOpResult::Failure;
        }
    }

    file.close();
    if (!file) {
        cerr << "Error: Failed to close the file.\n";
        return FileOpResult::Failure;
    }

    return FileOpResult::Success;
}

int main() {
    int quantity_of_lines;
    char filename[256];

    cout << "Enter file name: ";
    cin.getline(filename, sizeof(filename));

    cout << "Enter number of lines: ";
    cin >> quantity_of_lines;
    cin.ignore();


    string content[quantity_of_lines];

    cout << "Enter content to write into the file: ";
    for(int i = 0; i < quantity_of_lines; i++){
        getline(cin, content[i]);
    }
    FileOpResult result = write_to_file(filename, content, quantity_of_lines);

    if (result == FileOpResult::Success) {
        cout << "File written successfully.\n";
    } else {
        cerr << "Failed to write to the file.\n";
    }

    return 0;
}
