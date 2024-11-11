#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n, m;
    cout << "Введіть n: ";
    cin >> n;
    cout << "Введіть m: ";
    cin >> m;
    cout << "n- ++ m = "<< (n- ++ m) << endl;
    cout << "++ m > --n = " << (++ m > --n) << endl;
    cout << "-- n < ++m = " << (-- n < ++m) << endl;
    return 0;
}