#include <iostream>
using namespace std;
const int Size = 4;
int CalculateMatrix(int matrix[Size][Size]);
bool ColumValid(int matrix[Size][Size], int colum);

int main(){
    int my_matrix[Size][Size] = {};
    for(int i = 0; i<Size; i++){
        for(int j = 0; j<Size; j++){
            cin >> my_matrix[i][j];
        }
    }
    for(int i = 0; i<Size; i++){
        for(int j = 0; j<Size; j++){
            cout << my_matrix[i][j] << "\t";
            if(j == Size-1){
                cout << "\n";
            }
        }
    }
    cout << endl;
    int ans = CalculateMatrix(my_matrix);
    if(ans != 1){
        cout << "Добуток елементів матриці: " << ans << "\n";
    }else{
        cout <<"Нема таких стовпців\n";
    }
    return 0;
     
}

bool ColumValid(int matrix[Size][Size], int colum){
    for(int i = 0; i<Size; i++){
        if(matrix[0][colum] <= matrix[i][i]){
            return false;
        }
        if(matrix[0][colum] <= matrix[i][Size-1-i]){
            return false;
        }
    }
    return true;
}
int CalculateMatrix(int matrix[Size][Size]){
    int answer = 1;
    for(int i = 0; i<Size; i++){
        if (ColumValid(matrix, i)){
            cout << "Стовпчик " << i << " підходить;\n"; 
            for(int j = 0; j<Size; j++){
                answer *= matrix[j][i];
            }
        }
    }
    return answer;
}