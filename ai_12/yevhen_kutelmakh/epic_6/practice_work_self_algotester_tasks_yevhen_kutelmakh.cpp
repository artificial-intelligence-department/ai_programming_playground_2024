#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[100001];
    cin >> s;
    char ch = s[0];
    int was = 1;
    int l = strlen(s);
    for(int i = 1; i < l; i++) {
        if(s[i]==ch) {
            was++;
        } else {
            cout << was;
            was = 1;
            cout << ch;
            ch = s[i];
        }
    }
    cout << was << ch;
    return 0;
}