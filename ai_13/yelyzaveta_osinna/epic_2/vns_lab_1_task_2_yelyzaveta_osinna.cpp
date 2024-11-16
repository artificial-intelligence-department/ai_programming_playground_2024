// варіант 21
#include <iostream>
using namespace std;

int main() { 

    int n, m;

    cout << "Введіть значення n: ";
    cin >> n;
    cout << "Введіть значення m: ";
    cin >> m;
    
    cout << "n++ - m = " << n++ - m << endl;

    cout << "Чи виконується рівність m-- > n?" << endl;
    cout << (m > n) ? m : n;

    cout << "\n" << "Чи виконується рівність n-- > m" << endl;
    cout << (n > m) ? n : m;

    return 0;
}