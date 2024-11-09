#include <iostream>
using namespace std;

int main() {
    int k, count = 0;
    string s, word = "TOILET";

    cin >> k; 
    cin >> s;

    size_t pos = s.find(word);

    while (pos != string::npos) {
        count++;
        pos = s.find(word, pos + word.length()); 
    }

    if (count >= k) { 
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    } 

    return 0;
}

