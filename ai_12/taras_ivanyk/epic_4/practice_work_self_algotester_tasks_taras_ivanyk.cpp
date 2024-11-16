//***Депутатські гроші (Algotester)***
#include <iostream>
using namespace std;

int minBanknotes(int n) {
    int banknotes[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;
    
    for (int banknote : banknotes) {
        count += n / banknote;  
        n %= banknote;          
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << minBanknotes(n) << endl;
    return 0;
}

