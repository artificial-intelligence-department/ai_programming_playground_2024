#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    int changes1 = 0, changes2 = 0;
    
    for (int i = 0; i < n; ++i) {
        char expected1 = (i % 2 == 0) ? 'B' : 'Y';
        char expected2 = (i % 2 == 0) ? 'Y' : 'B';
        
        if (s[i] != expected1) changes1++;
        if (s[i] != expected2) changes2++;
    }

    cout << min(changes1, changes2) << endl;
    
    return 0;
}