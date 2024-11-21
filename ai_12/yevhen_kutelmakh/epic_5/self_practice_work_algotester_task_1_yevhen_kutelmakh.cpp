#include <iostream>
#include <string>
using namespace std;

bool check(string s1, string s2, int index) {
    bool b = true;
    for(int i = 1; i < s2.size(); i++) {
        if(s1[i+index] == '?')
            continue;
        if(s1[i+index]!=s2[i]) {
            b = false;
            break;
        }
    }
    return b;
}

int main() {
    string t;
    getline(cin, t);
    string s;
    getline(cin, s);
    int lenStart = t.size();
    int lenRes = s.size();
    bool d = false;
    for(int i = 0; i <= lenStart - lenRes; i++) {
        if(t[i]==s[0] || t[i]=='?') {
            if(check(t, s, i)) {
                d = true;
                break;
            }
        }
    }
    if(d) cout << "YES";
    else cout << "NO";
    return 0;
}
