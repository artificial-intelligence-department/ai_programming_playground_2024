// Variant 1
#include <iostream>

using namespace std;

int main()
{
    long long H,M,h,m,h1,m1,h2,m2,h3,m3;
    h=0;
    m=0;
    cin >> H >> M;
    h1=0;
    m1=0;
    h2=0;
    m2=0;
    h3=0;
    m3=0;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;
    h=h1+h2+h3;
    m=m1+m2+m3;
    
    if ((h1>0 && m1>0) || (h2>0 && m2>0) || (h3>0 && m3>0))
    {
        cout << "NO";
    }
    else if (H-h>0 && M-m>0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
