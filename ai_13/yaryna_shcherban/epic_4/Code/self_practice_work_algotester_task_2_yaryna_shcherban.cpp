#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); 

    set<string> uniqueDrinks; 
    for (int i = 0; i < n; i++) {
        string drink;
        getline(cin, drink); 
        uniqueDrinks.insert(drink); 
    }

    for (int i = 0; i < m; i++) {
        string drink;
        getline(cin, drink);
        uniqueDrinks.insert(drink); 
    }

    cout << uniqueDrinks.size() << endl;
    return 0;
}