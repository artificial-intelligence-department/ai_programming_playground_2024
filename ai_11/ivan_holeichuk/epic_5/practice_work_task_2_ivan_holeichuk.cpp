#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char* file_from, const char* file_to) {
    ifstream src(file_from, ios::binary);
    if (!src.is_open()) {
        return Failure;
    }

    ofstream dest(file_to, ios::binary);
    if (!dest.is_open()) {
        return Failure;
    }

    dest << src.rdbuf();

    if (src.fail() || dest.fail()) {
        return Failure;
    }

    src.close();
    dest.close();

    if (src.fail() || dest.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    char file_from[100], file_to[100];

    cout << "Enter the source filename: ";
    cin.getline(file_from, 100);

    cout << "Enter the destination filename: ";
    cin.getline(file_to, 100);

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        cout << "File copied successfully!" << endl;
    }
    else {
        cout << "Error copying file!" << endl;
    }

    return 0;
}
