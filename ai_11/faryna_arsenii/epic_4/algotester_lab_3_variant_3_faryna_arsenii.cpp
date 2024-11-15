#include <iostream>
#include <string>

using namespace std;

string compress_string(const string& s) {

    string s_compressed;

    int count = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            s_compressed += s[i - 1];            
            if (count > 1) {
                s_compressed += to_string(count);
            }
            count = 1; 
        }
    }

    s_compressed += s[s.length() - 1];
    if (count > 1){
        s_compressed += to_string(count);
    }

    return s_compressed;
}

int main() {
    string s;

    getline(cin, s);

    string result = compress_string(s);

    cout << result << endl;

    return 0;
}
