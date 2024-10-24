#include <iostream>
using namespace std;

int main(){
    long long H, M;
    bool Loss = false;

    cin >> H >> M;
    if (H<1 || M<1){
        return 0;
    }

    for(int i=0; i<3; i++){
        long long h, m;
        cin >> h >> m;
        if(h<0 ||m<0){
            return 0;
        }
        if(h>0 && m>0){
            Loss = true;
        }
        H -= h;
        M -= m;

    }
    if(H>0 && M>0 && !Loss){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
