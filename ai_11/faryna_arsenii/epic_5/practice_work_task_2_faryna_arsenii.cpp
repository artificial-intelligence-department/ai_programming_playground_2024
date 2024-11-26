#include <iostream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char* file_from, const char* file_to) {
    
    if (file_from == nullptr || file_to == nullptr) {
        cout << "Error: null file or content provided." << endl;
        return Failure;
    }

    FILE* file_from_1 = fopen(file_from, "rb");    if (file_from_1 == nullptr) {
        cout << "Error while reading the file: " << file_from << endl;
        return Failure;
    }

    FILE* file_to_1 = fopen(file_to, "wb");
    if (file_to_1 == nullptr) {
        cout << "Error while opening file for writing: " << file_to << endl;
        fclose(file_from_1);
        return Failure;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_from_1)) > 0) {
        // Якщо помилка при записі
        if (fwrite(buffer, 1, bytes_read, file_to_1) != bytes_read) {
            cout << "Error while writing to file: " << file_to << endl;
            fclose(file_from_1);
            fclose(file_to_1);
            return Failure;
        }
    }

    if (ferror(file_from_1)) {
        cout << "Error while reading from source file: " << file_from << endl;
        fclose(file_from_1);
        fclose(file_to_1);
        return Failure;
    }

    fclose(file_from_1);
    fclose(file_to_1);

    return Success;
}

int main() {

    char file_from_name[40] = "f1.txt";
    char file_to_name[40] = "f2.txt";

    FileOpResult result = copy_file(file_from_name, file_to_name); 

    if (result == Success) {
        cout << "From f1.txt to f2.txt data has been coppied successfully." << endl;
    } else {
        cout << "Error while copying the file." << endl;
    }

    return 0;
}
