#include <iostream>
#include <string>
using namespace std;

int countMeows(string s) {
    int meows = 0;
    for (size_t i = 0; i < s.length() - 1; ) {
        if (s[i] == s[i + 1]) {
            meows++;
            s.erase(i + 1, 1); 
            if (i > 0) i--;
        }
        else {
            i++;
        }
    }
    return meows;
}

int main() {
    string s;
    cin >> s;
    int result = countMeows(s);
    cout << result << endl;

    return 0;
}
