#include <iostream>
using namespace std;

int main(){
    int m, n;

    cout << "Введіть значення m: ";
    cin >> m;

    cout << "Введіть значення n: ";
    cin >> n;

    int first = m - (++n);
    cout << "Перший результат: " << first << endl;

    bool second = (++m) > (--n);
    cout << "Другий результат: " << second << endl;
    
    bool third = (--n) < (++m);
    cout << "Третій результат: " << third << endl;
    
    return 0;
}
