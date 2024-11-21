#include <iostream>
using namespace std;

int main() {
    int sizeOne, sizeTwo;

    cin >> sizeOne;
    int* arrOne = new int[sizeOne];
    for (int i = 0; i < sizeOne; i++) cin >> arrOne[i];

    cin >> sizeTwo;
    int* arrTwo = new int[sizeTwo];
    for (int i = 0; i < sizeTwo; i++) cin >> arrTwo[i];


    int sizeSame = 0;
    for (int i = 0; i < sizeOne; i++) {
        for (int j = 0; j < sizeTwo; j++) {
            if (arrOne[i] == arrTwo[j]) {
                sizeSame++;
                break;
            }
        }
    }

    int sizeDifferent = sizeOne + sizeTwo - sizeSame;

    cout << sizeSame << endl;
    cout << sizeDifferent;
    
    delete[] arrOne;
    delete[] arrTwo;

    return 0;
}














