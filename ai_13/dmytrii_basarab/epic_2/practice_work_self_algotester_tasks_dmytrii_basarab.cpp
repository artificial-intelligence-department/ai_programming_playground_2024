#include <iostream>
using namespace std;

int main()
{
int array[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int n;
int i;
int bank = 0;
cin >> n;

    for (i = 0; i < 9; i++) {
    while (array[i] <= n) {
        n -= array[i];
        bank++;
        }
    }

    cout << bank;

    return 0;
}