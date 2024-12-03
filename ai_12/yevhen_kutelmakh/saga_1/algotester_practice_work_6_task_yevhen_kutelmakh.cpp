#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int len = s.size();
    string pas;
    pas = s;
    int end = len - 1;
    int begin = 1; 
    for(int i = 1; i < len; i++) {
        if(i%2 == 0) {
            pas[i] = s[begin++];
        } else {
            pas[i] = s[end--];
        }
    }
    cout << pas;
    return 0;
}
