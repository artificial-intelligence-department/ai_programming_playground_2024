#include <iostream>

using namespace std;

int main()
{
    int l = 0;
    for (int j = 0; j < 200; j++)
    {
        if (j % 3 == 0)
        {
            l += j;
        }
    }
    cout << l;
}