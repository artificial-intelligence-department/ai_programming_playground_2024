#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName = "Test.txt";
    string userInput;

    ofstream outFile(fileName , ios::app);
    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }

    cout << "Введіть текст для запису у файл (для завершення введіть exit):" << endl;

    while (true) {
        getline(cin, userInput);
        if (userInput == "exit") {
            break;
        }
        outFile << userInput << endl;
    }

    outFile.close();

    cout << "Ви хочете зчитати вміст файлу? (Y/N): ";
    string answer;
    getline(cin, answer);

    if (answer == "Y") {
        ifstream inFile(fileName);
        if (!inFile) {
            cerr << "Не вдалося відкрити файл для читання!" << endl;
            return 1;
        }

        cout << "====================" << endl;
        cout << "Вміст файлу:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Читання файлу скасовано." << endl;
    }
    return 0;
}
