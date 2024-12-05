#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool mod_two;
    bool prev = true;

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        mod_two = ((a % 2) == 0);
        k += (prev ^ mod_two) && i;

        prev = mod_two;
    }
    cout << k;

    return 0;
}