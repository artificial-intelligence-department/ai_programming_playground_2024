#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string a; 
    bool correct = true;

    cin >> n;
    cin >> a;

  
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input != a) {
            correct = false;
        }
    }

  
    if (correct) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
