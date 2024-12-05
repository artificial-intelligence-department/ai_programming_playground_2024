#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        cerr << "Error: Null file path provided." << endl;
        return Failure;
    }

    if (!filesystem::exists(file_from)) {
        cerr << "Error: Source file does not exist: " << file_from << endl;
        return Failure;
    }

    ifstream input_file(file_from, ios::binary);
    if (!input_file.is_open()) {
        cerr << "Error: Failed to open source file: " << file_from << endl;
        return Failure;
    }

    ofstream output_file(file_to, ios::binary);
    if (!output_file.is_open()) {
        cerr << "Error: Failed to open destination file: " << file_to << endl;
        input_file.close();
        return Failure;
    }

    output_file << input_file.rdbuf();

    if (!output_file) {
        cerr << "Error: Write operation failed to file: " << file_to << endl;
        input_file.close();
        output_file.close();
        return Failure;
    }

    input_file.close();
    output_file.close();

    cout << "File successfully copied from " << file_from << " to " << file_to << "." << endl;
    return Success;
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";

    FileOpResult result = copy_file(source, destination);

    if (result == Success) {
        cout << "Operation completed successfully." << endl;
    } else {
        cout << "Operation failed." << endl;
    }

    return 0;
}