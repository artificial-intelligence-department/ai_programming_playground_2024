//1952
#include<iostream>
using namespace std;

int main()
{
    long long  n, k;
    cin>>n>>k;

    long long  a;
    for (int i = 0; i < k; i++)
    {
        cin>>a;

        while (n % a == 0)
        {
            n /= a;
        }
    }
    
    if (n == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}