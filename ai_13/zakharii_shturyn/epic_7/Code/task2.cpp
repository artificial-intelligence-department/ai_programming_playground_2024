#include <iostream>
using namespace std;

int main() {

    long long sum = 0;
    int Packs;
    cin >> Packs;
    for (int i = 0; i < Packs; i++) {
        int n;
        cin >> n;
        if (n != 0)
            sum += n - 1;
    }
    
    cout << sum;

    return 0;
}