#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    
    ofstream outf(name); 
    
    if (!outf) {
        cerr << "Error: can't open for writing" << endl;
        return Failure;
    }

    outf << content;

    if (outf.fail()) {
        cerr << "Error: writing to the file failed" << endl;
        return Failure;
    }

    outf.close();
    if (outf.fail()) {
        cerr << "Error: closing the file failed" << endl;
        return Failure;
    }

    return Success;
}

int main() {
    const char *filename = "SomeText";
    char text_content[256];
    
    cout << "Enter the content to write into the file: ";
    cin.getline(text_content, 256);
    
    FileOpResult result = write_to_file(filename, text_content);
    
    if (result == Success) {
        cout << "File written successfully." << endl;
    } else {
        cout << "Failed to write to the file." << endl;
    }

    return 0;
}
