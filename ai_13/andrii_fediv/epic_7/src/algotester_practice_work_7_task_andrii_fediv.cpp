#include <iostream>
#include <vector>

using namespace std;
using vint = vector<int>;
using ving = vector<string>;

int main()
{
    int n, acc = 0;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string v;
        getline(cin, v);
        char prev = ' ';
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == '#' && prev != '#')
                acc++;
            prev = v[i];
        }
    }
    cout << acc;
    return 0;
}