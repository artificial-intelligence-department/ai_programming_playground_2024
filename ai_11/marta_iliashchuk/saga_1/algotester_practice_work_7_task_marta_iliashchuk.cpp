#include <iostream>
using namespace std;

//Зайчик і галявини (412)

int main() {
    int n;
    int max_index = 0;

    cin >> n; 
    
    int halyavina[n]; 

    for (int i = 0; i < n; i++) {
        cin >> halyavina [i];
    }

    for (int i = 1; i < n; i++) {
        if (halyavina[i] > halyavina[max_index]) {
            max_index = i;
        }
    }

    cout << max_index << endl;

    return 0;
}