#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int crossings = 0; 

    bool isEvenSide = a[0] % 2 == 0;

    for (int i = 1; i < n; i++) {
        bool currentIsEven = a[i] % 2 == 0;
        if (currentIsEven != isEvenSide) {
            crossings++; 
        }
        isEvenSide = currentIsEven;
    }

    cout << crossings << endl;

    return 0;
}
