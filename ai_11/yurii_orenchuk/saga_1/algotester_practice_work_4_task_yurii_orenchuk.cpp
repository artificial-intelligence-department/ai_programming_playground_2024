#include <iostream>
using namespace std;

//1061
int main(){
    int n;
    int cnt1 = 0, cnt2 = 0, op;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == 1){
            cnt1++;
        }
        else if(op == 2){
            if(cnt1 == 0){
                cnt2++;
            } else cnt1--;
        } else return 0;
    }

    cout << cnt2;

    return 0;
}