#include <iostream>
#include <cstdio>
using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(char* name, char* content) {
    FILE* file = fopen(name, "w");

    if (file == nullptr) {
        return Failure;
    }

    if (fprintf(file, "%s", content) < 0) {
        fclose(file);
        return Failure;
    }

    if (fclose(file) != 0) {
        return Failure;
    }

    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    cout << "Enter name of your file: ";
    cin >> filename;
    cout << "Enter text which do you wanna to see insede: ";
    cin.ignore();
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "You createdd a file" << endl;
    }
    else {
        cout << "Error " << endl;
    }

    return 0;
}
