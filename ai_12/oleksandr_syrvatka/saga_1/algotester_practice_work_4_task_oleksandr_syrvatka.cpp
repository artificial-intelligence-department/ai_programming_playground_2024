#include <iostream>
using namespace std;

//Зробити паліндром

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1) {
        cout << "YES" << endl;  
    } else {
        cout << "NO" << endl;   
    }

    return 0;
}
