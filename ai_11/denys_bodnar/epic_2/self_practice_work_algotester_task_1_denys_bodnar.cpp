#include <iostream>
using namespace std;

int main() {
    long long a,b,c;
    cin >> a >> b >> c;

    long long summa_girls = a + b;

    if (summa_girls > c){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
