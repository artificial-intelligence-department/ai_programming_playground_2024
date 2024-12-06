#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int N, M, x, y  , maxi = 0 , buf;
    cin >> N >> M;
    cin >> x >> y;
    (x-1)*M + y;
    cout <<endl;
    buf = (y - 1) + x - 1;
    if(maxi < buf)
        maxi = buf;
    buf = ( M - y ) + x - 1;
    if(maxi < buf)
        maxi = buf;
    buf = ( M - y ) + (N-x);
    if(maxi < buf)
        maxi = buf;
    buf = (y - 1) + (N-x);
    if(maxi < buf)
        maxi = buf;
    
    for(int i = 1 ; i <= N*M ; i++){
        int otkl;

        if(i%M ==0)
            otkl = abs(M -y) + abs((i/M ) - x);
        else
            otkl = abs(i%M -y) + abs((i/M +1) - x);

        cout << maxi - otkl  <<" ";
        if(i % M == 0)
            cout <<endl;
    }

    return 0;    
}