#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int v = 0, k = 0, pv = 0, pk = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'V')
        {
            v++;
        }
        else if (s[i] == 'K')
        {
            k++;
        }
        if (v >= 11 && v >= k + 2)
        {
            pv++;
            k = 0;
            v = 0;
        }
        else if (k >= 11 && k >= v + 2)
        {
            pk++;
            k = 0;
            v = 0;
        }
    }
    cout << pk << ":" << pv << endl;
    if (k > 0 || v > 0)
    {
        cout << k << ":" << v << endl;
    }
}