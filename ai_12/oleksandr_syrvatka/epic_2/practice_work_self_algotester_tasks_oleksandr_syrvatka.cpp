#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n ; i++){
        cin >> ar[i];
    }

    for(int i = 0; i < n ; i++){
        for(int x = i + 1; x < n; x++ ){
            if (ar[x] < ar[i]){
                swap(ar[x], ar[i]);
            }
        }
    }
    if (ar[0] >89){
        cout << "Pidvyshchena";
    }
    else if (ar[0] > 50){
        cout << "Zvychaina";
    }
    else {
        cout << "Zabud pro stypendiiu";
    }       

    return 0;
}