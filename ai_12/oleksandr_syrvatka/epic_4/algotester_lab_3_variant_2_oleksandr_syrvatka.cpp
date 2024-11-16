#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,M,a = 0;
    cin >> N;
    int arr1[N];
    for(int i = 0; i < N; i++){
        cin >> arr1[i]; 
    }
    cin >> M;
    int arr2[M];
    for(int i = 0; i < M; i++){
        cin >> arr2[i]; 
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j<M;j++){
            if(arr1[i] == arr2[j]){
                a++;
                break;
            }
        }
    }
    cout << a << endl;
    cout << (N+M) - a;

    return 0;
}