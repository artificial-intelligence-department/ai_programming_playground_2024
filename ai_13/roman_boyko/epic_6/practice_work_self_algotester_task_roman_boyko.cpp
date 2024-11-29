#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N;
    int k = 0;
    cin >> N;
    cin.ignore();
    vector<string> w(N);
    for (int i = 0; i < N; i++)
    {
        getline(cin, w[i]);
    }
    for (int i = 0; i < N; i++)
    {
        bool inStr = false;
        for (char c : w[i])
        {
            if (c == '#')
            {
                if (!inStr)
                {
                    k++;
                    inStr = true;
                }
            }
            else
            {
                inStr = false;
            }
        }
    }
    cout << k;
}