//187
#include <iostream>
using namespace std;
const string VARIANT = "B187";
int main (){
   char board[1000][1000];
   int N;
   cin >> N;
   for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
        cin >> board[i][j];
    }}
    for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
        if(board[i][j] == 'C'){
            if (i+2 <=N && j+3 <= N && (board[i+2][j+3] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+2 << " " << j+3;
                return 0;
            }
            if (i+3 <=N && j+2 <= N && (board[i+3][j+2] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+3 << " " << j+2;
                return 0;
            }
            if (i - 3 >=1 && j- 2 >= 1 && (board[i - 3][j - 2] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j-2;
                return 0;
            }
            if (i - 2 >=1 && j-3 >= 1 && (board[i-2][j-3] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j-3;
                return 0;
            }
            if (i + 2 <=N && j-3 >= 1 && (board[i+2][j-3] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+2 << " " << j-3;
                return 0;
            }
            if (i + 3 <=N && j-2 >= 1 && (board[i+3][j-2] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+3 << " " << j-2;
                return 0;
            }
            if (i - 3 >=1 && j+2 <= N && (board[i-3][j+2] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j+2;
                return 0;
            }
            if (i - 2 >=1 && j+3 <= N && (board[i-2][j+3] == 'c'|| board[i+2][j+3] == 'k')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-2 << " " << j+3;
                return 0;
            }
        }
        if(board[i][j] == 'c'){
            if (i+2 <=N && j+3 <= N && (board[i+2][j+3] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+2 << " " << j+3;
                return 0;
            }
            if (i+3 <=N && j+2 <= N && (board[i+3][j+2] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+3 << " " << j+2;
                return 0;
            }
            if (i - 3 >=1 && j- 2 >= 1 && (board[i - 3][j - 2] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j-2;
                return 0;
            }
            if (i - 2 >=1 && j-3 >= 1 && (board[i-2][j-3] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j-3;
                return 0;
            }
            if (i + 2 <=N && j-3 >= 1 && (board[i+2][j-3] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+2 << " " << j-3;
                return 0;
            }
            if (i + 3 <=N && j-2 >= 1 && (board[i+3][j-2] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i+3 << " " << j-2;
                return 0;
            }
            if (i - 3 >=1 && j+2 <= N && (board[i-3][j+2] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-3 << " " << j+2;
                return 0;
            }
            if (i - 2 >=1 && j+3 <= N && (board[i-2][j+3] == 'C'|| board[i+2][j+3] == 'K')){
                cout << VARIANT << " " << i << " " << j<< " "<< i-2 << " " << j+3;
                return 0;
            }
        }
        if(board[i][j] == 'k'){
            if (i-1>=1 && j-1 >= 1 && board[i-1][j-1] == 'C'|| board[i-1][j-1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j-1;
                return 0;
            }
            if (i-1>=1  && board[i-1][j] == 'C'|| board[i-1][j] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j;
                return 0;
            }
            if (i-1>=1 && j+1 <=N && board[i-1][j+1] == 'C'|| board[i-1][j+1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j+1;
                return 0;
            }
            if (j-1 >= 1 && board[i][j-1] == 'C'|| board[i][j-1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i << " " << j-1;
                return 0;
            }
            if (j+1 <= N && board[i][j+1] == 'C'|| board[i][j+1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i << " " << j+1;
                return 0;
            }
            if (i+1<=N && j-1 >=1 && board[i+1][j-1] == 'C'|| board[i+1][j-1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j-1;
                return 0;
            }
            if (i+1<=N  && board[i+1][j] == 'C'|| board[i+1][j] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j;
                return 0;
            }
            if (i+1<=N && j+1 <=N && board[i+1][j+1] == 'C'|| board[i+1][j+1] == 'K'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j+1;
                return 0;
            }

        }
         if(board[i][j] == 'K'){
            if (i-1>=1 && j-1 >= 1 && board[i-1][j-1] == 'c'|| board[i-1][j-1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j-1;
                return 0;
            }
            if (i-1>=1  && board[i-1][j] == 'c'|| board[i-1][j] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j;
                return 0;
            }
            if (i-1>=1 && j+1 <=N && board[i-1][j+1] == 'c'|| board[i-1][j+1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i-1 << " " << j+1;
                return 0;
            }
            if (j-1 >= 1 && board[i][j-1] == 'c'|| board[i][j-1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i << " " << j-1;
                return 0;
            }
            if (j+1 <= N && board[i][j+1] == 'c'|| board[i][j+1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i << " " << j+1;
                return 0;
            }
            if (i+1<=N && j-1 >=1 && board[i+1][j-1] == 'c'|| board[i+1][j-1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j-1;
                return 0;
            }
            if (i+1<=N  && board[i+1][j] == 'c'|| board[i+1][j] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j;
                return 0;
            }
            if (i+1<=N && j+1 <=N && board[i+1][j+1] == 'c' || board[i+1][j+1] == 'k'){
                cout << VARIANT << " " << i << " " << j<< " "<< i+1 << " " << j+1;
                return 0;
            }

        }
   }
    }
    cout <<  VARIANT << " "<< "none";
    return 0;
}
