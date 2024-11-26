#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> array(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> array[i][j];
        }
    }
    int maxSum = INT_MIN;
    int r = 0;
    int c = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            int sum = 0;
            for (int k = i; k < 3; k++) {
                for (int l = j; l < 3; l++) {
                    sum += array[k][l];
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                r = i;
                c = j;
            }
        }
    }
    cout << endl;
    cout << "MainMatrix:" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "MaxMatrix 3*3: " << endl;
    for (int i = r; i < c + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "MaxSum of Matrix 3*3:" << endl;
    cout << maxSum;
    return 0;}