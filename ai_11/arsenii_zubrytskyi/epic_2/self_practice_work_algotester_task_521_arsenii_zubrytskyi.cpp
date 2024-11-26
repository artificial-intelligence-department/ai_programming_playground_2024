#include <iostream>
using namespace std;

int main() {
    int lviv, kyiv, donetsk, kharkiv;
    
    cin >> lviv >> kyiv >> donetsk >> kharkiv;
    
    int totalSouvenirs = lviv + kyiv + donetsk + kharkiv;
    
    cout << totalSouvenirs << endl;
    
    return 0;
}
