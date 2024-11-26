
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, Scomp;
    cin >> s;
    int count = 1; 
    for (size_t i = 1; i <= s.size(); ++i) { 
        if (i < s.size() && s[i] == s[i - 1]) {
            ++count; 
        } else {
            Scomp += s[i - 1]; 
            if (count > 1) {
                Scomp += to_string(count); 
            }
            count = 1; 
        }
    }
    cout << Scomp; 
    return 0;
}