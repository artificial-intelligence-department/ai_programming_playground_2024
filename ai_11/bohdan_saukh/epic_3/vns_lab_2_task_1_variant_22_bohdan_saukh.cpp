#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    double res = 0;
    double n = 15;
    
    
    for(int i = 1; i<=n; i++){
        res += (pow(n, log(n))/pow(log(n), n));
    }
    
    cout<<res;
    return 0;
}