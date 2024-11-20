#include <iostream>
#include <numeric>
using namespace std;
int main(){
    long n;
    long long result, b, y;
    cin >> n >> y >> b;
    result = n/y + n/b - n/((b/gcd(b, y)) * y);
    if (n%b == 0 || n%y == 0){
        result--;
    }
    cout << result;
    return 0;
}
