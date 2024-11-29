#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream source(file_from, ios::binary);
    if (!source.is_open()) {
        return Failure;
    }

    ofstream destination(file_to, ios::binary);
    if (!destination.is_open()) {
        source.close();
        return Failure;
    }

    destination << source.rdbuf();

    if (source.fail() || destination.fail()) {
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();
    return Success;
}

int main() {
    char source_filename[256];
    char destination_filename[256];

    cout << "Enter source filename: ";
    cin.getline(source_filename, sizeof(source_filename));

    cout << "Enter destination filename: ";
    cin.getline(destination_filename, sizeof(destination_filename));

    FileOpResult result = copy_file(source_filename, destination_filename);
    if (result == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }

    return 0;
}
