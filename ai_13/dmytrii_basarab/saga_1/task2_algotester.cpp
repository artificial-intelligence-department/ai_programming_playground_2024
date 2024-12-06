#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> a(n); 


    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;


    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    long long max_eatable = sum - n; 

    cout << max_eatable << endl;

    return 0;
}