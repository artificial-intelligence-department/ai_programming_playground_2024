#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> uniqueLetters(s.begin(), s.end());

    cout << uniqueLetters.size() << endl;

    return 0;
}

