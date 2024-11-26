#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string st = "";
    int s[100];  
    
    for (int i = 0; i < m; i++) {
        s[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++) {
            if (a[j] == '*') {
                s[j]++;
            }
        }
    }
    
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            if (s[j] == i) {
                s[j]--;
                st += '*';
            } else {
                st += '.';
            }
        }
        cout << st << endl;
        st = "";
    }
    
    return 0;
}
