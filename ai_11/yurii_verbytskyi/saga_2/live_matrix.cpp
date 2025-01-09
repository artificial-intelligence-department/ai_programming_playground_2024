#include <iostream>

using namespace std;

// 41 64 75 78 84 97    
// 44 29 45 47 36 56  
// 79 14 63 27 89 62 
// 42 21 95 75 63 47
// 31 68 96 22 47 56


// 41 64 75 78 84     
// 44 29 45 47 36   
// 79 14 63 27 89 
// 42 21 95 75 63 
// 31 68 96 22 47 

int** reverse_matrix(int** matrix, int &size){
    int** rotated_matrix = new int*[size];
    for(int i = 0; i < 5; i++){
        rotated_matrix[i] = new int[5];
    }

    
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            int left = 0;
            int right = size - 1;
            while (left < right) {
                int temp = matrix[left][i];
                matrix[left][i] = matrix[right][i];
                matrix[right][i] = temp;
                left++;
                right--;
            }
        }
    }

    return matrix;
}

int main(){
    int size = 5;
    int* mass = new int[5];
    int** matrix = new int*[5];
    for(int i = 0; i < 5; i++){
        matrix[i] = new int[5];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> matrix[i][j];
        }
    }

    for(int col = 0; col < 5; col++){
        int min = matrix[0][0];
        for(int row = 0; row < 5; row++){
            if(min > matrix[row][col]){
                min = matrix[row][col];
            }
        }
        mass[col] = min;  
    }

    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << mass[i] << " ";
    }
    cout << endl;
    cout << endl;
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // вивід з нижнього кута
    // for(int i = 4; i >= 0; i--){
    //     for(int j = 4; j >= 0; j--){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //поворот навколо діагоналі
    // for(int i = 0; i < 5; i++){ 
    //     for(int j = 0; j < 5; j++){
    //         if(i < j){
    //             swap(matrix[i][j], matrix[j][i]);
                
    //         }
    //     }
    // }

    // int** matrix_1 = new int*[size];
    // for(int i = 0; i < size; i++){
    //     matrix_1[i] = new int[size];
    // }
    int** matrix_1 = reverse_matrix(matrix, size);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix_1[i][j] << " ";
        }
        cout << endl;
    }

    delete[] mass;

    for(int i = 0; i < 5; i++){
        delete[] matrix[i];
    }
    delete[] matrix;


    return 0;
}