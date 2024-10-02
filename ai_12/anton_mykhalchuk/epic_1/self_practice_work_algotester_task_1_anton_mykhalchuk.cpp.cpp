#include <iostream>
#include <string>
using namespace std;

bool is_base(int n, int k, int base) {
    int digit;
    while (n > 0) {
        digit = n % base;
        if (digit != k){
            return false;
        }
        n /= base;
    }
    return true;
}

int find_base(int n, int k) {
    int base;
    
    for (base=k; base<=n; base++) {
        if (n==k) {
            return n+1;
        }
        
        if (is_base(n, k, base)) {
            return base;
        }
    }

    return -1;
}

int main() {
    int i, n, k, x;

    cin >> n >> k;

    x = find_base(n,k);

    cout << x << endl;

    return 0;
}