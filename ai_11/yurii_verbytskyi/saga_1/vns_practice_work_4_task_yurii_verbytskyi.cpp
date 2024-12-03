#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double mass[5]; 
    double sum; 
    for(int i = 0; i < 5; i++){
        cin >> mass[i];
        sum += mass[i];
    }
    /*в коді використаний for цикл для запису елементів масиву, використаний одновимірний масив 
    для зберігання 5-ти елементів, а також одна цілочисельна змінна(і), щоб обмежити цикл for*/
    cout << "Arithmetic mean: "<< sum/5; 
}