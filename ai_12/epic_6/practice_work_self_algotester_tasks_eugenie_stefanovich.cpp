#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

int main() {
    int n ;
    long  sum = 0;
    cin >> n;

    vector<int> base(n);
    for (int i = 0; i < n; i++) {
        cin >> base[i];
    }

   
    int gcd = base[0];
    for (int i = 1; i < n; i++) {
          gcd = std::gcd(gcd, base[i]);
; 
    }
    for(int i = 0; i < n; i++)
        sum += base[i];
  
    cout << endl << sum / gcd;
    return 0;
}
