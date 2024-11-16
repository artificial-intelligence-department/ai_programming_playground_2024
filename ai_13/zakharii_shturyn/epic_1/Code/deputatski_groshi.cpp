#include <iostream>
using namespace std;

int main() {

    int NumOfBanknotes = 0;
    int Value;
    cin >> Value;

    int Banknote[9] = {1,2,5,10,20,50,100,200,500};

    for(int i = 0; i < 9; i++) {
        while (Value - Banknote[8-i] >= 0){
            Value -= Banknote[8 - i];
            NumOfBanknotes++; 
        }
    }

    cout << NumOfBanknotes;
    return 0;
}