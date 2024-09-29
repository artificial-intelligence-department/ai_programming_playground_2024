#include <iostream>
using namespace std;
int main()
{
    int k,n,m;
    int i=0;
    cin>>n>>m>>k;
    if (k==1)
    {
        if (n>=m)
        {
            cout<<'0';
        }
        else
        {
            cout<<'-'<<'1';
        }
        return 0;
    }
    while (n<m)
    {
       n*=k;
       i++;
    }
    cout<<i;
    return 0;
}
