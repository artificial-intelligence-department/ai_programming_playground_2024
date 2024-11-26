#include <iostream>
#include <string>

using namespace std;

string compressString(const string& s) {
    string compressed = "";
    int n = s.size();
    
    int i = 0;
    while (i < n) {
        char currentChar = s[i];
        int count = 1;
        
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        
        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
        }
        
        i++;
    }
    
    return compressed;
}

int main() {
    string s;
    
    cin >> s; 

    cout << compressString(s) << endl; 

    return 0;
}