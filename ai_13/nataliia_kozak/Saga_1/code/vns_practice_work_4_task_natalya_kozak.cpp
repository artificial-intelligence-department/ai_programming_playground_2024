#include <iostream>
using namespace std;
int main(){
    int n, a = 1, sum = 0;
    cout << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        sum += a;
        a += 2;
    }
    cout << sum;
    return 0;
}