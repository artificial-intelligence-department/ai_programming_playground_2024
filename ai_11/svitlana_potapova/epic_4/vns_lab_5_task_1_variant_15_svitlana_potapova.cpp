#include <iostream>
using namespace std;

void elSum(int array[100][100], int rows, int cols){
    int maxS = 0;
    for(int i=0; i<cols-1; i++){
        int S = 0;
        for(int j=0; j<rows-(i+1); j++){
            S += array[j][i];
        }
        cout << S << " ";
        maxS = (S > maxS) ? S : maxS;
    }
    cout << endl << "Максимальна сума: " << maxS;
}
int main(){
    int array[100][100];
    int rows, cols;
    cin >> rows >> cols;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cin >> array[i][j];
        }
    }
    cout << "Матриця " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";  
        }
        cout << endl; 
    }
    elSum(array, rows, cols);
    return 0;
}
