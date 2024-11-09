#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Введіть значення для n: ";
    cin >> n;
    cout << "Введіть значення для m: ";
    cin >> m;
    
    cout << "Результат виразу ++n*++m: " << ++n * ++m << endl;

    bool result2 = m++ < n;
    cout << "Результат виразу m++ < n: " << (result2 ? "true" : "false") << endl;

    bool result3 = n++ > m;
    cout << "Результат виразу n++ > m: " << (result3 ? "true" : "false") << endl;

    return 0;
}