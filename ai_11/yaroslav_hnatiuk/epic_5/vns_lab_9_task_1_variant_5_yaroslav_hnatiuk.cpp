#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

void UpdateFile();

int main() {
    string answer;

    cout << "Update file?: ";
    cin >> answer;
    if (answer == "Yes" ) {
        UpdateFile();
        cout << "File updated\n";
    } else cout << "File not updated\n";

    int startCopyLine;
    cout << "Enter the line from which copying will begin: ";
    cin >> startCopyLine;

    ifstream fileOne("F1.txt");
    ofstream fileTwo("F2.txt");

    vector<string> vecOne;
    vector<string> vecTwo;

    string line;
    while (getline(fileOne, line)) vecOne.push_back(line);
    
    for (int i = startCopyLine - 1; i < startCopyLine + 4; i++) {
        if (i + 1 > vecOne.size()) break;

        vecTwo.push_back(vecOne[i]);
    }

    for (int i = 0; i < vecTwo.size(); i++) fileTwo << vecTwo[i] << endl;

    fileOne.close();
    fileTwo.close();
    
    cout << "File copied\n";

    int vowelsNum;
    for (int i = 0; i < vecTwo.size(); i++) {
        for (char j : vecTwo[i]) {
            if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u' || j == 'y') vowelsNum++;
        }
    }

    cout << "Number of vowels in F2: " << vowelsNum;

    return 0;
}

void UpdateFile() {
    ofstream file("F1.txt");

    vector<string> data; 
    srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
        string str;
        for (int j = 0; j < 8; ++j) {
            char randomChar = 'a' + rand() % 26;
            str += randomChar;
        }
        data.push_back(str);
    }

    for (int i = 0; i < data.size(); i++) file << data[i] << endl;

    file.close();
}
