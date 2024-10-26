#include <iostream>
using namespace std;

int main() {
    int N, M, a, b, c;
    cin >> N;
    int r[N];
    for(int i=0; i < N; i++) {
        cin >> r[i];
    }
    cin >> a >> b >> c;
    for(int i=0; i<N; i++) {
        if (r[i]==a || r[i]==b || r[i]==c){
            for(int j=i; j <N-1; j++) {
                r[j] = r[j+1];
            }
            N--;
            i--;
        }
    }
    if(N>0){
        M=N-1;
    } else {N=0;}
    int r_new[M];
    for(int i=0; i< M; i++) {
        r_new[i] = r[i]+r[i+1];
    }
    cout << M << "\n";
    for(int i=0; i < M; i++) {
        cout << r_new[i] << " ";
    }
    return 0;
}