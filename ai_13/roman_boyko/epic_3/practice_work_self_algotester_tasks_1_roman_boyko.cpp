#include <iostream>
using namespace std;

int main()
{
    int money[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    long int n;
    int k = 0;
    cin >> n;
    for (int i = 0; i < 9; i++)
    {
        k += n / money[8 - i];
        n = n % money[8 - i];
    }
    cout << k;
}