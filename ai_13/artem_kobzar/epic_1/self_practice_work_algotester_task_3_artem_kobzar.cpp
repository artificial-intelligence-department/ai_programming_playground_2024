#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> drinks;  
    string drink;

    for (int i = 0; i < n; i++) {
        cin >> drink;
        drinks.insert(drink);  
    }

   
    for (int i = 0; i < m; i++) {
        cin >> drink;
        drinks.insert(drink);  
    }


    
    cout << drinks.size() << endl;

    return 0;
}
