#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr || strlen(name) == 0 || strlen(content) == 0) {
        return Failure;
    }
    ofstream file(name);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file: " << name << endl;
        return Failure;
    }

    try {
        file.exceptions(ios::failbit | ios::badbit); 
        file << content;
    } catch (const ios_base::failure &e) {
        cerr << "Error writing to file: " << e.what() << endl;
        file.close();
        return Failure;
    }
    file.close();
    return Success;
}
int main() {
    char file_name[100] = {};
    char content[250] = {};

    cout << "Enter file name: ";
    cin.getline(file_name, 100);

    if (cin.fail() || strlen(file_name) == 0) {
        cerr << "Error: Invalid file name.\n";
        return 1;
    }

    cout << "Enter content: ";
    cin.getline(content, 250);

    if (cin.fail() || strlen(content) == 0) {
        cerr << "Error: Invalid content.\n";
        return 1;
    }

    FileOpResult result = write_to_file(file_name, content);
    if (result == Success) {
        cout << "The file has been written successfully.\n";
    } else {
        cerr << "Error: Failed to write to file.\n";
    }

    return 0;
}
