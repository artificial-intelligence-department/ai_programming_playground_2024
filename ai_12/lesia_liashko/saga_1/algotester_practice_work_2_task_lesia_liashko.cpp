#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    if (a + 1 < b) 
    cout << a + 1 << endl;
    else if (b + 1 < a) 
    cout << b + 1 << endl;
    else cout << -1 << endl;
}

