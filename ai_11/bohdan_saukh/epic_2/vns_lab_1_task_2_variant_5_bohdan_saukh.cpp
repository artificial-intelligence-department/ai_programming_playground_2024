#include <iostream>

using namespace std;

int main()
{
    int n, m, old_n, old_m;
    
    cout << "Введіть значення n: " << endl ;
    cin >> n;
    cout << "Введіть значення m: " << endl ;
    cin >> m;    
    
    //онавлення значень змінних m i n
    old_n = n;
    old_m = m;

    //виведення результату
    cout << "Результат першої операції: " << --m-++n << endl;
    
    n = old_n;
    m = old_m;
    
    bool op = m*n<n++;
    //виведення результату
    cout << "Результат другої операції: " << op << endl;
    
    n = old_n;
    m = old_m;
    
    bool op1 = n-->m++;
    //виведення результату
    cout << "Результат третьої операції: " << op1 << endl;    
    
    return 0;
}