#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
long int n, k;
cin >> n >> k;

vector<long int> a(n);


int b = 0;
int f = 0;

for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] >= k){
        ++b;
        f = max(f, b);  
    } else{
        b = 0;
    }
}
cout << f << endl;
    return 0;
}
