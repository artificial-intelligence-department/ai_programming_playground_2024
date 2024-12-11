#include <iostream>

using namespace std;

int main(){

    float matrix1[4][4];
    float matrix2[4][4];
    float result[4][4];

    cout<<"введіть матрицю A"<<endl;
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            cin>>matrix1[i][j];
        }
    }

    cout<<"введіть матрицю B"<<endl;
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            cin>>matrix2[i][j];
        }
    }

    
    
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            for (size_t k = 0; k < 4; k++){
            result [i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    cout<<"результат (A x B):"<<endl;
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            cout<< result [i][j]<< " ";
        }
        cout <<endl;
    }

    return 0;
}
