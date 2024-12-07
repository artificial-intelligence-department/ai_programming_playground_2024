#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    set<string> uniqueStrings;

    for (int i = 0; i < s.length(); i++) {
        string modifiedString = s.substr(0, i) + s.substr(i + 1); // Видаляємо i-й символ
        uniqueStrings.insert(modifiedString);
    }
    cout << uniqueStrings.size() << endl;
}
