#include <iostream>
#include <algorithm>
using namespace std;


int main(){

int N, M;
cin >> N >> M;
int matrix[N][M];
int x,y;
cin >>x >> y;
x--;
y--;
for(int i = 0; i<N; i++){
    for(int j = 0; j<M;j++){
        int distance = abs(i-x)+abs(j-y);
        matrix[i][j] = max(x,N-x-1) + max(y, M-y-1) - distance;
        
    }
}

for (int i = 0; i<N; i++) {
        for (int j = 0;j<M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}