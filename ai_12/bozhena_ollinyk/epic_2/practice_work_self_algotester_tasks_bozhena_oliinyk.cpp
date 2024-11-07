#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main (){
    int L, W, U, D;
    // L - diametr of circle; W - length of closed mouth; U - mowement of upper jaw; D - movement of bottom jaw

    cin >> L >> W >> U >> D;

    if (((U + D) <= L) && (W <= L)){
        cout << "Three times Sex on the Beach, please!" << endl;
    } 
    else {
        cout << "Forget about the cocktails, man!" << endl;
    }

    return 0;
}