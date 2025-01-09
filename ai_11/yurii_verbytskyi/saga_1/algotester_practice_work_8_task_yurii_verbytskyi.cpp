#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;  

    string compressed = "";  
    int n = S.length();
    
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && S[i] == S[i + 1]) {
            i++;
            count++;
        }

        compressed += S[i];
        if (count > 1) {
            compressed += to_string(count); 
        }
    }

    cout << compressed << endl;  

    return 0;
}
