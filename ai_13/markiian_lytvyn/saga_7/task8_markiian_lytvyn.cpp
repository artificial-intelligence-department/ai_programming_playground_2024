#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if ( a < 1 || b < 1 || c < 1 || a > 47 || b > 47 || c > 47){
        cout << "Error";
    }
    if ((a + b) <= 47|| (a + c) <=47 || (b + c) <=47){
        cout << "YES";
    } else{
        cout << "NO";
    }
}       