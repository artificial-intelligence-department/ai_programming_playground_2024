#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    int c = 0;
    cin >> N;
    int* arr1=new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
}
    cin >> M;
    int* arr2=new int[M];
    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
    }
    for(int i = 0; i < N; i++){
            for(int j = 0; j < M;j++){
                if(arr1[i] == arr2[j]){
                    c++;
                    break;
                }
            }
        }
    cout << c << endl;
    cout << N + M - c;
    delete[] arr1;
    delete[] arr2;
    return 0;
}