#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int c;
    if (a != b){
        if ((a + 1) < b){
            c = a + 1;
            cout << c;
        }else{
        if (( b + 1) < a){
            c = b + 1;
            cout << c;
        }else{
            cout << -1;
        }
    }}
    else{
        return 0;
    }
}