#include <iostream>

using namespace std;

int main()
{
    long A[4];
    long B[4];
    long C[4];
    bool er = false;
    bool win = true;
    for (int i = 0; i<4; i++) {
        cin >> A[i];
        C[i] = A[i];
    }
    for (int i = 0; i<4; i++) {
        cin >> B[i];
    } 
    for (int i = 0; i < 4; i++) {
        if(A[i]-B[i] < 0){
            er = true;
        }
        if(A[i]-B[i] == 0){
            win = false;
        }        
    }
    if (er == false && win == true){
        for (int i = 0; i<4; i++){
            for (int j = 0; j<4; j++){
                for (int k = 0; k<4; k++) {
                    C[i] = A[i]-B[i];
                    if(C[j] >= 2*C[k]){
                        win = false;
                        break;
                    } 
                }
                if (win == false){
                    break;
                }
            }
            if (win == false){
                break;
            }
        }
        if (win == true){
            cout << "YES";
        }else{
            cout << "NO"; 
        }
    }else{
        if(er == true){
            cout << "ERROR";
        }else{
            cout << "NO"; 
        }
    }
    return 0;
}

