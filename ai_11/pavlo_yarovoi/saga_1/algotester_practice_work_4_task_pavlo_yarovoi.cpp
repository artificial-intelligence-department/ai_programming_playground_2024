#include "iostream"
using namespace std;
int main(){
    long long int  s;
    long double a1, a13, d;
    cin >> a1 >> a13;

    d = (a13-a1) / 12;
    if (abs(d-int(d)) > 0){
        cout << "-1";
    }
    else{
        s = (13*(a1+a13))/2;
        cout << s;
    }

    return 0;
}
