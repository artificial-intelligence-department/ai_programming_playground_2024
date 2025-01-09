#include <iostream>
#include <fstream>
using namespace std;

int main() {

// write

    ofstream outFile("example.binary", ios::binary);

    if (!outFile) {
        cerr << "Error, can not open a file for writing!" << endl;
        return 1;
    }

    int number = 12345;
    char character = 'A';

    outFile.write(reinterpret_cast<char*>(&number), sizeof(number));
    outFile.write(&character, sizeof(character));

    outFile.close();
    cout << "Data was succesfully written to a binary file)" << endl;

// read
    ifstream inFile("example.binary", ios::binary);
    
    if (!inFile) {
        cerr << "Error, can not open a file for writing!" << endl;
        return 1;
    }
    int number_read;
    char character_read;

    inFile.read(reinterpret_cast<char*>(&number_read), sizeof(number_read));
    inFile.read(&character_read, sizeof(character_read));

    inFile.close();

    cout << "Number read: " << number_read << endl;
    cout << "Character read: " << character_read << endl;
    return 0;
}
