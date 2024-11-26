#include <iostream>
using namespace std;

//0961
int main(){
    int x, y, z, res;
    cin >> x >> y >> z;

    if(z < (x-y)){
        cout << "-1";
        return 0;
    }

    if(z > (x+y)){
        res = x + y;
    }
    else if(z < (x+y)){
        res = z;
    }

    cout << res;

    return 0;
}