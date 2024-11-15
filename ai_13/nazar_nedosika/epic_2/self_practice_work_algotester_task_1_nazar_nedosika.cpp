#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> denominations = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0; 

    for (int denom : denominations) {
        if (n == 0) 
        break;
        count += n / denom;
        n %= denom; 
    }

    cout << count << endl;

    return 0;
}
