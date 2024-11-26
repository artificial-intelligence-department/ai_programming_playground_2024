#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,m;
    cin >> N;
    int r[N];
    for(int i = 0; i < N; i++){
        cin >> r[i]; 
    }
    
    sort(r,r + N);

    if(N != 1){
        if((r[N-2] - r[0]) < (r[N-1] - r[1])){
            m = (r[N-2]- r[0]);
        }else{
            m = (r[N-1] - r[1]);
        }
    }else{
        m = 0;
    }
    cout << m;
    return 0;
}