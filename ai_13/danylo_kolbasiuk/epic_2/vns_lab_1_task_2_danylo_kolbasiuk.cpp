#include <iostream>

using namespace std;

int main()
{
    long long int n,m;
    cin >> n >> m;
    long long a=n---m; // First, n-m will be calculated and it will be the value of a, then n-- is calculated
    bool b=m--<n; // First, m<n and the value into b, then m--
    bool c=n++>m; // First, n>m and the value into c, then n++
    cout << "a,b,c in order: " << a << " " << b << " " << c << endl;
    cout << "n,m in order: " << n << " " << m;
}