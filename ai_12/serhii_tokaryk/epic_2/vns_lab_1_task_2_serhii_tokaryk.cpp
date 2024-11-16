#include <iostream>
using namespace std;

int main() {
    int n, m;

    
    cout << "Введіть n: ";
    cin >> n;
    cout << "Введіть m: ";
    cin >> m;

    
    int n1 = n, m1 = m; 
    int condition1 = ++n1 * ++m1;
    cout << "Результат ++n * ++m: " << condition1 << " (n=" << n1 << ", m=" << m1 << ")" << endl;

   
    n = n1; m = m1; 
    bool condition2 = m++ < n;
    cout << "Результат m++ < n: " << (condition2 ? "істина" : "хибність") << " (n=" << n << ", m=" << m << ")" << endl;

   
    n = n1; m = m1;
    bool condition3 = n++ > m;
    cout << "Результат n++ > m: " << (condition3 ? "істина" : "хибність") << " (n=" << n << ", m=" << m << ")" << endl;

    return 0;
}

