#include <iostream>

using namespace std;
int main(){

    unsigned int a, b, c;
    cin >> a >> b;

    if(a>b && a-b > 1){
        c += ++b;
        cout << c;
    }else if(a<b && b-a > 1){
        c += ++a;
        cout << c;
    }else cout << -1;

    return 0;
}