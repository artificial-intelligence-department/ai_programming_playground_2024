#include <iostream>

using namespace std;

int main()
{
    double arr[6] = {};

    for (int i = 1; i <= 5; i++)
    {
        cout << "Write a number" << endl;
        cin >> arr[i];

        cout << "Average is: " << (arr[1] + arr[2] + arr[3] + arr[4] + arr[5]) / i << endl;
    }

    return 0;
}