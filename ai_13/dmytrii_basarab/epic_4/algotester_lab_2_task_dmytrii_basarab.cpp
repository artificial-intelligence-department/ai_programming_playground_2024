#include <iostream>
#include <algorithm>
 int k = 0;
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N<=0) return 0;

    int* r = new int[N];
    for (int i=0; i < N; i++) {
        cin >> r[i];
        if(r[i]<0) {
            return 0;
        }
    }

for (int k = 0;k<N;k++) {
    for (int j=k+1;j<N;j++) {
        if(r[k]>r[j]) {
        swap(r[k],r[j]);
        }
    }
}
    if(N==1){
    cout << r[0] - r[0] << endl;
    return 0;
}

int m1;
int m2;

int* ptr1 = &m1; //показав роботу і синтаксис вказівників
int* ptr2 = &m2;

*ptr1 = r[N - 2] - r[0];
*ptr2 = r[N - 1] - r[1];

if (*ptr1<*ptr2) {
    cout << *ptr1;
} else cout << *ptr2;

delete[] r;
return 0;
}

