#include<iostream>
using namespace std;

int main()
{
    long long health_points, magic_points;

    cin>>health_points>>magic_points;

    long long h, m;
    for (int i = 0; i < 3; i++)
    {
        cin>>h>>m;

        if ((h > 0) && (m > 0)) 
        {
            health_points = -1;
        }
        else if (h > 0) 
        {
            health_points -= h;
        }
        else magic_points -= m;
    }

    if ((health_points <= 0) || (magic_points <= 0)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
    return 0;
}