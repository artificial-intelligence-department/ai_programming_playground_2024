// Algotester (problem 11) Marichka and cookies
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);

    long long sum = 0;

    for (int i = 0; i < n; ++i){
        cin >> A[i];

        sum += A[i]-1;
    }
    cout << sum;

    return 0;
}