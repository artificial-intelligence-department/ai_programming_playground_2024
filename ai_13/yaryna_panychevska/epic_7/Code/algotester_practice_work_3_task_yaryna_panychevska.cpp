#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int girls = a + b;
    
    if (girls > c)
    {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}