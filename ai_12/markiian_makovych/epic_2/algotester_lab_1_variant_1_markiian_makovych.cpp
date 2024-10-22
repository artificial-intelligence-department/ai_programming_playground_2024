#include <iostream>

using namespace std;

int main()
{
    long long cube = 0;
    long long prevCube = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> cube;
        if (cube <= 0)
        {
            cout << "ERROR" << endl;
            return 0;
        }
        if (cube > prevCube && prevCube > 0)
        {
            cout << "LOSS" << endl;
            return 0;
        }
        prevCube = cube;
    }

    cout << "WIN" << endl;
    return 0;
}