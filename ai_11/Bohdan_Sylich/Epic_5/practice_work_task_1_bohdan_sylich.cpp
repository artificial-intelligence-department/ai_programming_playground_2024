#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter filename: ";
    cin.getline(filename, sizeof(filename));

    cout << "Enter content: ";
    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file(filename, content);
    if (result == Success) {
        cout << "File written successfully." << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}
