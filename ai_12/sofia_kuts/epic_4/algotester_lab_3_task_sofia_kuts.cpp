#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s; 

    string result = ""; 
    int count = 1;

    for (size_t i = 1; i <= s.length(); ++i) {
        if (i < s.length() && s[i] == s[i - 1]) {
            ++count;
        } else {
            result += s[i - 1]; 
            if (count > 1) {
                result += to_string(count); 
            }
            count = 1; 
        }
    }

    cout << result << endl; 
    return 0;
}
