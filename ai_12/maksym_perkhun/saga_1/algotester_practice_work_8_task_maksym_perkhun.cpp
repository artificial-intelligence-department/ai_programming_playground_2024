//Літня школа
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    int arr[k];
    int i = 0;
    if (k * 3 < n|| k > n){
        cout << "Impossible";
    }
    else{
        for (int l = 0; l < k; l++){
            arr[l] = 1;
        }
        n -= k;
        int i = 0;
        while (n > 1){
            arr[i] = arr[i] + 2;
            n -= 2;
            i++;
        }
        if (n == 1){
            arr[i] += 1;
        }
        for (int j = 0; j < k; j++){
            cout << arr[j] << " ";
        }
        }
    return 0;
}
