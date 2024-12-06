#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canFormName(const string& givenWord, const string& targetName) {
    unordered_map<char, int> letterCount;
    for (char c : givenWord) letterCount[c]++;
    for (char c : targetName) {
        if (letterCount[c]-- <= 0) return false;
    }
    return true;
}

int main() {
    string givenWord, targetName;
    cin >> givenWord >> targetName;
    cout << (canFormName(givenWord, targetName) ? "YES" : "NO") << endl;
    return 0;
}