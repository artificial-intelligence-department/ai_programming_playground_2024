#include <iostream>
using namespace std;

int main()
{
    long long int n,m;
    cout << "Введіть n: ";
    cin >> n;
    cout << "Введіть m: ";
    cin >> m;
    long long a = ++n * ++m; 
    bool b = m++ < n; 
    bool c = n++ > m; 
    cout << "a: " << a << " " << "b: " << b << " " << "c: " << c << endl;
    cout << "n: " << n << " " << "m: " << m;}