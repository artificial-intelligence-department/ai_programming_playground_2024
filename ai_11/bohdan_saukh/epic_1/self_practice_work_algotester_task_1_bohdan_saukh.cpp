#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long n;
    int b, y;
    cin >> n >> y >> b;

    long r = n / y + n / b;

    long lcm = (b / gcd(b, y)) * y;

    r -= n / lcm;

    if (n % b == 0 || n % y == 0) {
        r--;
    }

    cout << r;
    return 0;
}
