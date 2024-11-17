#include <iostream>
using namespace std;
int main ()
{
    int n;
    cout << "n = ";
    cin >> n;

    int sum = 0; 

    for (int i = 1; i < n + 1; i++){

        sum +=i;
    }

    cout << "Сума перших " << n << " цілих позитивних чисел: " << sum << endl;

    return 0;
}