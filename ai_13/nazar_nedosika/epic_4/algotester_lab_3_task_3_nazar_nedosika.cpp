#include <iostream>
#include <string>
using namespace std;

string compress_string(const string& s) {
    string result;
    int n = s.length();
    
    for (int i = 0; i < n; ) {
        char current_char = s[i];
        int count = 1;
        
        while (i + 1 < n && s[i + 1] == current_char) {
            count++;
            i++;
        }
        
        result += current_char;
        if (count > 1) {
            result += to_string(count);
        }
        
        i++;
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    cout << compress_string(s) << endl;
    
    return 0;
}
