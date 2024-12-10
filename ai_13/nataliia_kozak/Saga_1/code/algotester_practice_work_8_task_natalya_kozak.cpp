#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(){
    long long total = 0;
    int x, n;
    cin >> n;
    vector <long long> l;
    for(int i = 0; i< n; i++){
        cin >> x;
        total += x;
        l.push_back(x);
    }
    long long result = l[0];
    for(int i:l){
        result = gcd(result, i);
    }

    cout << total / result;
    return 0;

}