#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    double m = 0;
    double n = 0;

    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;

    cout << "1) ++n*++m = " << ++n*++m << "\nОскільки +nn = n + 1 = " << n << ", ++m = m + 1 = " << m << " преінкрементно, тобто спочатку змінні збільшують на 1, а потім відбувається їхнє множення\n";
    n--;
    m--;
    if (m++<n)
    {
        cout << "2) m++<n = True\nОскільки m++ = m + 1 = " << m << " постінкрементно, тобто спочатку відбувається порівняння, а лиш потім m++\n";
    }
    else
    {
        cout << "2) m++<n = False\nОскільки m++ = m + 1 = " << m << " постінкрементно, тобто спочатку відбувається порівняння, а лиш потім m++\n";
    }
    m--;
    if (n++>m)
    {
        cout << "3) n++>m = True\nОскільки n++ = n + 1 = " << n << " постінкрементно, тобто спочатку відбувається порівняння, а лиш потім n++\n";
    }
    else
    {
        cout << "3) n++>m = False\nОскільки n++ = n + 1 = " << n << " постінкрементно, тобто спочатку відбувається порівняння, а лиш потім n++\n";
    }
    n--;
}

