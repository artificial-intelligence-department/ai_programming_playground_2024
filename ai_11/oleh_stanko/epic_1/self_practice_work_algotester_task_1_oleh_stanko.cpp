#include <iostream>

using namespace std;

int main()
{
    int k,n,m;//k - у скільки разів маг може збільшити зріст; n-зріст баскетболіста; m-мінімальний зріст, яким би був задоволений наш герой
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
            cout<<"-1";
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
