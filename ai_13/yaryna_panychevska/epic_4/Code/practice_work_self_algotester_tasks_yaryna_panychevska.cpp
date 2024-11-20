#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int all = n + m;
    
    vector <string> drinks(all);
    set<string>unique_drinks;

    for (int i = 0; i < all; i++)
    {
        getline(cin, drinks[i]);
        unique_drinks.insert(drinks[i]);
    }
    cout << unique_drinks.size() << endl;
    return 0;

}