//borshch, potato and salad
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int i;
    cin >> i;
    int a[i], b[i], c[i];
    for (int j = 0; j < i; j++){
        cin >> a[j] >> b[j] >> c[j];
    }
    sort(a,a + i);
    sort(b,b + i);
    sort(c,c + i);
    int A, B, C, m;
    if(i%2 == 0){
        A = round((a[i/2 - 1] + a[i/2])/(float)2);
        B = round((b[i/2 - 1] + b[i/2])/(float)2);
        C = round((c[i/2 - 1] + c[i/2])/(float)2);
    }
    else{
        A = a[i/2];
        B = b[i/2];
        C = c[i/2];
    }
    int result = 0;
    for(int j = 0; j < i; j++){
        result += abs(a[j] - A) + abs(b[j] - B) + abs(c[j] - C);
    }
    cout << result;
    return 0;
}