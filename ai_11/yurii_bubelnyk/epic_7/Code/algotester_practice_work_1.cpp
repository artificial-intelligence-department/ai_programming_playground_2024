#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    // перевірка меж
    if(a < 1 || a > 1e9 || b < 1 || b > 1e9 || c < 1 || c > 1e9) return 1;
    
    if(a + b > c)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
   
    return 0;
}
