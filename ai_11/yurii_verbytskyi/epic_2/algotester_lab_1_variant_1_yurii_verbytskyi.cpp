#include <iostream>
using namespace std;
int main(){
long long H, M;
long long h[3];
long long m[3];
cin >> H >> M;
for(int i = 0; i < 3; i++){
    cin >> h[i] >> m[i];
}
    H = H - (h[0] + h[1] + h[2]);
    M = M - (m[0] + m[1] + m[2]);
    for(int i=0; i<3; i++){
        if (h[i] > 0 && m[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if( H > 0 && M > 0){
        cout << "YES";
    }else cout << "NO";  
    return 0;
}
