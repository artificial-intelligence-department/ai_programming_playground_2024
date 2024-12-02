#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int data = 123456;

    ofstream outFile("binary.dat", ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(&data), sizeof(data));
        outFile.close();
    }

    int readData;
    ifstream inFile("binary.dat", ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
        cout << readData << endl;
        inFile.close();
    }

    ifstream inTextFile("example.txt");
    if (!inTextFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inTextFile, line)) {
        cout << line << endl;
    }

    inTextFile.close();
    return 0;
}
