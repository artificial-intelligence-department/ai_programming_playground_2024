#include <iostream>
#include <set>
using namespace std;

//День програміста (211)

int main() {
    int n, m;
    set<string> drinks;
   
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string alco;
        cin >> alco;
        drinks.insert(alco); 
    }

    for (int i = 0; i < m; ++i) {
        string alco;
        cin >> alco;
        drinks.insert(alco); 
    }

   cout << drinks.size() <<endl;

   return 0;
}