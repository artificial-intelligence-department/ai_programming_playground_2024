#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int operations;

    string action;
    int amount;
    bool inDebt = false;
    int balance = 0;

    cin >> operations;
    cin.ignore();
    for (int i = 0; i < operations; i++) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        ss >> action >> amount;

        if (action == "earn")
        {
            balance += amount;
        }
        if (action == "spend")
        {
            balance -= amount;
        }

        if (balance < 0)
        {
            inDebt = true;
        }
    }

    if (inDebt)
    {
        cout << "debt";
    }
    else {
        cout << "chinazes";
    }

    return 0;
}