#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
        sum += x[i] - 1;
    }
    cout << sum;
    return 0;
}
