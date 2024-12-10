#include <iostream>

using namespace std;

int main()
{
    int n, m;
    // n - кількість артилерійських установок
    // m - кількість будинків
    cin >> n >> m;
    while (n>0 && m>0)
    {
        m-=n;
        n--;
    }
    if (m>0) 
    {
        cout << "Special military operation completely failed!";
    }
    else if (n>0)
    {
        cout << "BNR will finally be free!";
    }
    else 
    {
        cout << "Best possible scenario!";
    }
    return 0;
}
