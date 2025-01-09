#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char* array = new char[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    int V = 0;
    int K = 0;
    int win_v = 0;
    int win_k = 0;

    for (int i = 0; i < n; ++i)
    {
        if (array[i] == 'V')
        {
            ++V;
        }
        if (array[i] == 'K')
        {
            ++K;
        }

        if (V >= 11 && (V - K) >= 2)
        {
            ++win_v;
            V = 0;
            K = 0;
        }

        if (K >= 11 && (K - V) >= 2)
        {
            ++win_k;
            V = 0;
            K = 0;
        }
    }

    cout << win_k << ':' << win_v << endl;

    if (V != 0 || K != 0) {
        cout << K << ':' << V;
    }

    return 0;
}





