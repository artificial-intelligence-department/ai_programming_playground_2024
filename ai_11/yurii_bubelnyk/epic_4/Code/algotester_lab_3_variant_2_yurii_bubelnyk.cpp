#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N, M;

    cin >> N;
    
    if(N < 0 || N > 100)
        return 1;

    vector<int> arrN(N);

    for(int i = 0; i < N; i++){
        cin >> arrN[i];
        if(arrN[i] < 0 || arrN[i] > 100){
            return 1;
        }
    }

    cin >> M;

    if(M < 0 || M > 100)
        return 1;

    vector<int> arrM(M);

    for(int i = 0; i < M; i++){
        cin >> arrM[i];
        if(arrM[i] < 0 || arrM[i] > 100){
            return 1;
        }
    }
    
    int unique = 0;
    int common = 0;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arrM[i] == arrN[j]){
                common++;
                break;
            }
        }
    }
    
    unique = N+M-common;

    cout << common << endl;
    cout << unique << endl;

    return 0;
}