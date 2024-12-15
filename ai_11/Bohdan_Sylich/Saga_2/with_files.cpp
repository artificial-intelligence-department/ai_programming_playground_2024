#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writePlainText(const string& filename, const string& data) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << data;
        outFile.close();
        cout << "Дані записано у файл: " << filename << endl;
    } else {
        cout << "Не вдалося відкрити файл для запису: " << filename << endl;
    }
}
void readPlainText(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "Дані з файлу " << filename << ":\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Не вдалося відкрити файл для читання: " << filename << endl;
    }
}
int main() {
    string plainTextData = "Hello World \nLine №2";
    string plainTextFile = "example.txt";

    writePlainText(plainTextFile, plainTextData);
    readPlainText(plainTextFile);

    return 0;
}
