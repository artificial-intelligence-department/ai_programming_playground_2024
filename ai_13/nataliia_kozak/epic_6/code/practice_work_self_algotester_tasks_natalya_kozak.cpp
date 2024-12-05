#include <iostream>
using namespace std;
int main(){
    int N0, M0, i;
    cin >> N0 >> M0;
    char desert[N0][M0];
    for(int n = 0; n < N0; n++){
        for(int m = 0; m < M0; m++){
            cin >> desert[n][m];
        }
    }
    cout << endl;
    for(int m = 0; m < M0; m++){
        for(int n = N0-1; n > 0; n--){
            i = 1;
            if(desert[n-1][m] == 'S'){
                while(desert[n-1 + i][m] == 'O' && (n-1+i < N0)){
                    desert[n-1 + i][m] = 'S';
                    desert[n- 2 + i][m] = 'O';
                    i++;
                }
            }
        }
    }
    for(int n = 0; n < N0; n++){
        for(int m = 0; m < M0; m++){
            cout << desert[n][m];
        }
        cout << endl;
    } 
    return 0;
}