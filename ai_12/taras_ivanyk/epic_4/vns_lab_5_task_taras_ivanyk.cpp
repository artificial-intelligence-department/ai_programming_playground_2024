#include <iostream>
using namespace std;

void transpose(int n, int matrix[][100]){
    for (int i = 0; i < n;++i){
        for(int j = 0; j < n; ++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
bool isSymetric(int n, int matrix[][100]){
    
    transpose(n, matrix);
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(matrix[i][j] != matrix[j][i]){
                return false;
            }
        }
    }   
    return true;
}

int main(){
    int n;
    cout << "Enter size of matrix n x n" <<endl;
    cin >> n;

    int matrix[100][100];

    cout << "Enter elements of this matrix: "<< endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
           cin >> matrix[i][j];
        }
    }   
    if (isSymetric(n, matrix)){
        cout << "Your matrix is symetric!" << endl;
    } else{
        cout << "Your matrix is not symetric!" << endl;
    }
    return 0;
}