#include <iostream>
using namespace std;
int main()
{
    long int H, M, h1, h2, h3, m1, m2, m3;

    cin>>H>>M;
    cin>> h1>>m1;
    cin>> h2>>m2;
    cin>> h3>>m3;

    if ((h1 >0 and m1 >0) or(h2 >0 and m2 >0) or (h3 >0 and m3 >0) or (H <=(h1 + h2 + h3) or M <=(m1 + m2 + m3))){
        cout<<"NO";
    }
    else{
         cout<<"YES";
    }
    return 0;
}