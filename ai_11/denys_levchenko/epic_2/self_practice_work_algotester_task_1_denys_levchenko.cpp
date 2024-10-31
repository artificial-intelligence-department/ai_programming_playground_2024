#include <iostream>
using namespace std;

int main() {
    int n;
    n >= 1; n <= 10000;
    cin >> n;
    
    int x[10000];
    for (int i = 0; i < n; i++) { 
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) { // віднімаємо від останнього передостаннє і так далі
        if (x[i] - x[i-1] < 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
} // https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40784#mySolutions
