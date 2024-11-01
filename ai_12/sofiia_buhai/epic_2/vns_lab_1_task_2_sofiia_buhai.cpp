#include <iostream>
#include <math.h>
using namespace std;

int main() {

    double n, m, ans_1, ans_2, ans_3;

    cin >> n >> m;

    ans_1 = n++ - m;
    ans_2 = m-- > n ;
    ans_3 = n-- > m;

    cout << "\n1) n++ - m = " << ans_1;
    cout << "\n2) m-- > n =  " << ans_2;
    cout << "\n3) n-- > m =  " << ans_3;
}
