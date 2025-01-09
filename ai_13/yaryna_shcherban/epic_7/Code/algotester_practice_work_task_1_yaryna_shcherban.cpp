#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> denominations = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    int count = 0; 
    
    for (int denomination : denominations) {
        if (n == 0) break; 
        count += n / denomination; 
        n %= denomination; 
    }
    
    cout << count << endl; 
    return 0;
}