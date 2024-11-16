//v1
#include <iostream>
using namespace std;
int main(){
    unsigned long long h,m;
    long long H, M;
    string res = "";
    cin >> H >> M;
    for(int i=0; i < 3; i++){
        cin >> h >> m;
        if(h != 0 && m != 0){
            res = "NO";
        }
        else{
            if(h != 0){
                H -= h;
            }
            else{
                M -= m;
            }
            if(H <= 0 || M <= 0){
                res = "NO";
            }
        }
        if(i==2 && res != "NO"){
            res = "YES";
        }
    }
    cout << res;
    return 0;
}

