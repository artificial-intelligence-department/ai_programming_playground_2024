#include <iostream>
using namespace std;

int main()
{
int array[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
//в коді використаний одновимірний масив 
int n;
int i;
int bank = 0;
cin >> n;

    for (i = 0; i < 9; i++) {//в коді використаний for цикл 
    while (array[i] <= n) {//в коді використаний while цикл
        n -= array[i];
        bank++;
        }
    }

    cout << bank;

    return 0;
}