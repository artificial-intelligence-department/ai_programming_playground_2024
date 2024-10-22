#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string action;
    int value;
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> action >> value;
        if (action == "earn")
        {
            balance += value;
        }
        else
        {
            balance -= value;
        }
        if (balance < 0)
        {
            cout << "debt";
            exit(0);
        }
    }
    cout << "chinazes";
}
