#include <iostream>

using namespace std;

int main()
{
    int number, sum;
    cin >> number;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    cout << sum;
    return 0;
}

