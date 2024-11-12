#include <iostream>

using namespace std;

int main(){

int N, M;
cin >> N >> M;
int array[N][M];

for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
        cin >> array[i][j];
    }
}

int maxSum = INT_MIN;
int Row = 0, Col = 0;

for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 3; j++) {
        int prevsum = 0;
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                prevsum += array[k][l];
            }
        }
        if (prevsum > maxSum) {
            maxSum = prevsum;
            Row = i;
            Col = j;
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
for (int i = Row; i < Row + 3; i++) {
    for (int j = Col; j < Col + 3; j++) {
        cout << array[i][j] << " ";
    }
    cout << endl;
}
cout << endl;

cout << "MaxSum of Matrix 3*3:" << endl;
cout << maxSum;



    return 0;
}
