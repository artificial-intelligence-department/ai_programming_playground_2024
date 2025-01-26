#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int count = 0;
    cout << "C135" << " ";
    for (int i = b; i >= a; i--)
    {
        if (count >= 10000)
        {
            return 0;
        }
        if (i % 16 == 12 || i / 12 == 16 || i / pow(16, 2) == 12 || i / pow(16, 3) == 12 || i / pow(16, 4) == 12)
        {
            count++;
            cout << i << " ";
        }
    }
    if (count == 0)
    {
        cout << "none";
    }
    return 0;
}
