//877
#include<iostream>
using namespace std;

int main()
{
    long long  n, a;
    cin>>n;
    
    long long min = 10000000000, count = 0;
    for (long long i = 0; i < n; i++)
    {
        cin>>a;
        if (a <= min)
        {
            count++;
            min = a;
        }
    }
    
    cout<<count<<endl;

    return 0;
}