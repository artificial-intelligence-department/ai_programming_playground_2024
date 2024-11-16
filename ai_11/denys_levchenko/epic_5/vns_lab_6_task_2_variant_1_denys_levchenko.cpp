#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <Windows.h>



using namespace std;
int main() {
    SetConsoleOutputCP(65001);
    char s[256];
    cout << "Введіть рядок (до 255 символів): ";
    gets(s); 

    stringstream ss(s);
    string word;
    map<string, int> wordCount;

    while (ss >> word) {
        wordCount[word]++;
    }


    cout << "Слова, які зустрічаються один раз: ";
    for (const auto& pair : wordCount) {
        if (pair.second == 1) {
            cout << pair.first << " ";
        }
    }
    cout << endl;

    return 0;
}
