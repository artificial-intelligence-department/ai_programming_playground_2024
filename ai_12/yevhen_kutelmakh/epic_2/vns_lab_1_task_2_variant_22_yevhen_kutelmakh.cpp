#include <iostream>
using namespace std;
int main() {
    double m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;
    double res1 = ++n*++m;
    double res2 = m++<n;
    double res3 = n++>m;
    cout << "++n*++m = " << res1 << "\n";
    cout << "m++<n = " << res2 << "\n";
    cout << "n++>m = " << res3 << "\n";
    return 0;
}
/*
Преінкремент виконується перед виконанням операції,
а постінкремент після тому фактично маємо:
(n+1)*(m+1) = res1
(m+1)<(n+1) = res2, (m+1) = (m+2)
(n+1)>(m+2) = res3, (n+1) = (n+2)
*/