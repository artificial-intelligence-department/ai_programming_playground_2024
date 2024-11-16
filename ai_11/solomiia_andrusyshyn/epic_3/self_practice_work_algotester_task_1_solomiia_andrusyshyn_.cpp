#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

bool isValidDrinkName(const string& name) {
    if (name.length() < 1 || name.length() > 7) 
    {
        return false;
    }
   for (char c : name) {
    if (c < 'a' || c > 'z') 
    {
        return false;
    }
}

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n >= 777 || m <= 0 || m >= 777) {
        cout << "Error: n and m must be between 0 and 777." << endl;
        return 1;
    }

    unordered_set<string> drinks;

    for (int i = 0; i < n; ++i) {
        string drink;
        cin >> drink;
        if (isValidDrinkName(drink)) 
        {
            drinks.insert(drink);
        } else {
            cout << "Error: Invalid drink name." << endl;
            return 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        string drink;
        cin >> drink;
        if (isValidDrinkName(drink)) {
            drinks.insert(drink);
        } else {
            cout << "Error: Invalid drink name." << endl;
            return 1;
        }
    }

    cout << drinks.size() << endl;

    return 0;
}