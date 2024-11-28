#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// C:\Users\Yura\Desktop\c++\epic_5(1).txt шлях до файлів
// C:\Users\Yura\Desktop\c++\epic_5(2).txt

enum class FileOpResult {
    Success,  
    Failure  
};

FileOpResult copy_file(char *file_from, char *file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        cerr << "Error: Invalid files provided.\n";
        return FileOpResult::Failure;
    }

    ifstream from(file_from, ios::in | ios::binary);
    if (!from) {
        cerr << "Error: Unable to open file for copying.\n";
        return FileOpResult::Failure;
    }

    ofstream to(file_to, ios::out | ios::binary);
    if (!to) {
        cerr << "Error: Unable to open file for pasting.\n";
        return FileOpResult::Failure;
    }

    to << from.rdbuf();

    if (!from || !to) {
        cerr << "Error: File copy operation failed.\n";
        return FileOpResult::Failure;
    }
    from.close();
    to.close();

    return FileOpResult::Success;
}

int main() {
    char file_from[256];
    char file_to[256];

    cout << "Enter the name of the source file: ";
    cin.getline(file_from, sizeof(file_from));

    cout << "Enter the name of the destination file: ";
    cin.getline(file_to, sizeof(file_to));

    if (copy_file(file_from, file_to) == FileOpResult::Success) {
        cout << "File copied successfully.\n";
    } else {
        cerr << "File copy failed.\n";
    }

    return 0;
}
