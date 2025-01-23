#include <iostream>

using namespace std;


int main() {
    int a,b;
    int sum = 0;
    int count=0;
    cin >> a >> b; // 2 5   2 3 4 5
    if (b > 1000000) return 0;
    if (a > b) return 0;
    int n = b - a + 1;
    int* arr = new int[n];
    int* arrc = new int[n];
    bool find = false;
    arr[0] = a;
    for (int i = 1; i < n;i++) {
        arr[i] = arr[i-1] + 1;
    }

for (int i = 0; i < b-a+1; i++) {
    arrc[i] = arr[i];
}

cout << "C126" << " ";

    for (int i = 0; i < b - a + 1; i++ ) {

                if (arrc[i] >= 1000000) {
            n = 1000000;
        } else if (arrc[i] >= 100000) {
            n = 100000;
        } else if (arrc[i] >= 10000) {
            n = 10000;
        } else if (arrc[i] >= 1000) {
            n = 1000;
        } else if (arrc[i] >= 100) {
            n = 100;
        } else if (arrc[i] >= 10) {
            n = 10;
        } else if (arrc[i] >= 1) {
            n = 1;
        }
            while (n != 0) {
                sum += arrc[i] / n; 
                arrc[i] -= n*(arrc[i]/n);
                n = n / 10;
            }



    if (sum <= 40) {
        find = true;
        cout << arr[i] << " ";
        count++;
        if (count >= 10000) return 0;
    }
    sum = 0;
    }



        if (find == false) {
            cout << "none";
        }
    
    

    return 0;
}
