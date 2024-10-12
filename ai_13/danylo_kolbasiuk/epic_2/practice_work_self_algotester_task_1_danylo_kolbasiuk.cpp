#include <iostream>

using namespace std;

int main() 
{
    long long int a[5];
    bool error = false;
    bool loss = false;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++) {
        if (a[i] <= 0) {
            error = true;
            break;
        }
        if (i > 0 && a[i - 1] < a[i]) {
            loss = true;
            break;
        }
    }
    if (error)
        cout << "ERROR" << endl;
    else if (loss)
        cout << "LOSS" << endl;
    else
        cout << "WIN" << endl;
}
