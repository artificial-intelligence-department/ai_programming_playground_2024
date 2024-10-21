#include <iostream>
using namespace std;

int main(){
    int n;
    long long a;
    long long cookies=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        cookies += a-1;
    }
    cout << cookies;
    return 0;
}
