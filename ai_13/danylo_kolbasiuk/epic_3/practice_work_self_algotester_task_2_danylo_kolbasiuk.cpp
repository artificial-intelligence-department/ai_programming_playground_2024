#include <iostream>
using namespace std;
int main()
{
    int s,a,b,c;
    int days=0;
    cin >> s >> a >> b >> c;
    while(true)
    {
        if (s>=(a+2*b+c))
        {
            s-=a+2*b+c;
            days++;
        }
        else
        {
            break;
        }
    }
    cout << days;
}