#include <iostream>
using namespace std;
int main(){
    int n;
    double s;
    cin >> n;
    for(double i = 1; i <= n; i++){
        s += 1 / i;
    }
    cout << s;
    return 0;
}
