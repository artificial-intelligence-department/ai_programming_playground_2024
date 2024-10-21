#include <iostream>
using namespace std;

int main(){
    int n_o, m_o;

    cout << "Введіть значення n: " << endl ;
    cin >> n_o;

    cout << "Введіть значення m: " << endl ;
    cin >> m_o;

    int n = n_o;
    int m = m_o;

    int operation_1 = (n--) - m;
    cout << "Результат першої операції: " << operation_1 << endl;

    n = n_o;
    m = m_o;

    bool operation_2 = (m--) < n;
    cout << "Результат другої операції: " << operation_2 << endl;

    n = n_o;
    m = m_o;
    
    bool operation_3 = (n++) > m;
    cout << "Результат третьої операції: " << operation_3 << endl;

    return 0;
} 