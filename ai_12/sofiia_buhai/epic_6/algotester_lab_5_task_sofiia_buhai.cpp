#include <iostream>
#include <vector>
#include <cmath>
#include <cinttypes>
#include <cstdio>

int main(){
    unsigned long long a, x;
    uint64_t b=0;
    int N, r=0, c=0;
    std::vector<bool> row(8, 0);
    std::vector<int> answer;
	std::vector<std::vector<bool>> board(8, row);
    std::cin >> a;
    std::cin >> N;
    std::vector<int> R(N), C(N);
    for(int i=0; i<N; i++){
        std::cin >> R[i] >> C[i];
        R[i]--;
        C[i]--;
    }

    while(a>0){
        board[r][c]=a%2;
        a/=2;
        c++;
        if(c==8){
            c = 0;
            r++;
        }
    }

    for(int n=0; n<N; n++){
        for(int i=0; i<8; i++){
            if(board[R[n]][i]==1){
                board[R[n]][i]=0;
            } else {
                board[R[n]][i]=1;
            }
        }
        for(int i=0; i<8; i++){
            if(board[i][C[n]]==1){
                board[i][C[n]]=0;
            } else {
                board[i][C[n]]=1;
            }
        }
        if(board[R[n]][C[n]]==1){
            board[R[n]][C[n]]=0;
        } else {
            board[R[n]][C[n]]=1;
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j]==1){
                x = pow(2, j+i*8);
                b+= x;
            }
        }
    }

    std::cout << b;

    return 0;
}