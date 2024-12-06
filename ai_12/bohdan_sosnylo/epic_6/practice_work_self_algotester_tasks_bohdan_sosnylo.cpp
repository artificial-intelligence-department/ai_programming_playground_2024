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
        if (i % 2 == 0) {  
            if (s[i] != 'B') {
                changes1++;
            }
        } else {  
            if (s[i] != 'Y') {
                changes1++;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {  
            if (s[i] != 'Y') {
                changes2++;
            }
        } else { 
            if (s[i] != 'B') {
                changes2++;
            }
        }
    }
    
    cout << min(changes1, changes2) << endl;

    return 0;
}
