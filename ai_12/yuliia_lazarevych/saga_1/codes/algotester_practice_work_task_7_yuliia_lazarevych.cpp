//допоможе чи заб'є

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readInput(int &k, string &s) { //використовую перевантаження функцій для зчитування змінних
    cin >> k >> s;
}

void readInputFromFile(const string &filename, int &k, string &s) {
    ifstream inFile(filename);
    inFile >> k >> s;
}

bool checkMessage(int k, const string &s) {
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find("TOILET", pos)) != string::npos) {
        count++;
        pos += 6;
    }

    return count >= k;
}

void writeResultToFile(const string &filename, const string &result) {  //використовую функцію для запису результату у файл(робота з файлами)
    ofstream outFile(filename);
    outFile << result << endl;
}

int main() {
    int k;
    string s;
    
    readInput(k, s);
    string result = checkMessage(k, s) ? "YES" : "NO";
    cout << result << endl;

    writeResultToFile("output.txt", result); //записує результати у файл

    return 0;
}

