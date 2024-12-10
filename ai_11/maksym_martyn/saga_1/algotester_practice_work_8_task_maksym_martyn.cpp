#include <iostream>
using namespace std;

int main() {
unsigned l, w, u, d;
cin >> l >> w >> u >> d;
if ( l >= 1 && l <= 1000000000 && w >= 1 && w <= 1000000000 && u >= 1 && u <= 1000000000 && d >= 1 && d <= 1000000000){
    if (l <= w && l <= (u + d)) {
    cout << "Three times Sex on the Beach, please!";
 } else {
    cout << "Forget about the cocktails, man!";
 }
}

return 0;
}