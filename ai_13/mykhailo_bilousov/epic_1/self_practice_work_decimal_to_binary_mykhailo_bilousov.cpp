#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string bin;
    while(n >= 1) {
        if(n & 1) bin += "1";
        else bin += "0";
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    cout << bin << endl;
}