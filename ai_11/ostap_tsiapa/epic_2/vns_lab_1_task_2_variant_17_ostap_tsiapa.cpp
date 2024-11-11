#include <iostream>
#include <cmath>

using namespace std;

int main (){
    
    int m, n, result1;
    bool result2, result3;

    cout << "Введіть змінну m: ";
    cin >> m;
    cout << "Введіть змінну n: ";
    cin >> n;

    result1 = n-- - m;
    cout << "\nРезультат1 = " << result1 << "\nПеревірка1: \nm: " << m << "\nn: "<< n << endl;
    result2 = m-- < n;
    cout << "\nРезультат2: " << result2 << endl;
    cout << "Перевірка2: \nm: " << m << "\nn: " << n << endl;
    result3 = n++ > m;
    cout << "\nРезультат3: " << result3 << endl;
    cout << "Перевірка3: \nm: " << m << "\nn: " << n << endl;

return 0;
}