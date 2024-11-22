#include <iostream>
#include <string>

using namespace std;

string compressString(const string& s) {
    string result;
    int count = 1;

    for (size_t i = 1; i <= s.size(); ++i) {
        
        if (i == s.size() || s[i] != s[i - 1]) {
            result += s[i - 1]; 
            if (count > 1) {
                result += to_string(count); 
            }
            count = 1; 
        } else {
            ++count; 
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    string compressed = compressString(s);
    cout << compressed << endl;

    return 0;
}
