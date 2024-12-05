#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    string result;
    int count = 1;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }
    
    result += s[s.length() - 1];
    if (count > 1) {
        result += to_string(count);
    }
    
    cout << result << endl;
    
    return 0;
}

