/*
- знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
- знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
- знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
- знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
- вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
- вивести матрицю з нижнього правого кута з ліва на право, з верху вниз 
- обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
- зробити поворот матриці на 90 градусів 
- перевірити чи матриця симетрична 
- далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
не факт що все зроблю:)
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

const int SIZE = 5; // matrix 5x5
const int SIZE1 = 6; // matrix 5x6

void filled_matrix(vector<vector<int>> &matrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matrix[i][j] = (1 + rand() % 100); // avoid 0
        }
    }

}

void print_matrix(const vector<vector<int>>& matrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void find_min_elements_in_columns(vector<vector<int>>& matrix){

    vector<int> array(SIZE);
    for (int j = 0; j < SIZE; j++){
        array[j] = INT_MAX;
    }

    for (int j = 0; j < SIZE; j++){
        for (int i  = 0; i < SIZE; i++){
            if (array[j] > matrix[i][j]){
                array[j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }
    cout << endl;

}

void find_max_elements_in_columns(vector<vector<int>>& matrix){

    vector<int> array(SIZE);
    for (int j = 0; j < SIZE; j++){
        array[j] = INT_MIN;
    }

    for (int j = 0; j < SIZE; j++){
        for (int i  = 0; i < SIZE; i++){
            if (array[j] < matrix[i][j]){
                array[j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }
    cout << endl;

}

void find_min_elements_in_rows(vector<vector<int>>& matrix){

    vector<int> array(SIZE);
    for (int i = 0; i < SIZE; i++){
        array[i] = INT_MAX;
    }

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (array[i] > matrix[i][j]){
                array[i] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }
    cout << endl;

}

void find_max_elements_in_rows(vector<vector<int>>& matrix){

    vector<int> array(SIZE);
    for (int i = 0; i < SIZE; i++){
        array[i] = INT_MIN;
    }

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (array[i] < matrix[i][j]){
                array[i] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }
    cout << endl;

}

void print_matrix_from_right_corner_up_and_down(vector<vector<int>>& matrix){

    for (int j = SIZE - 1; j >= 0; j--){
        for (int i = SIZE - 1; i >= 0; i--){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void print_matrix_from_right_corner_from_left_to_right(vector<vector<int>>& matrix){

    for (int i = SIZE - 1; i >= 0; i--){
        for (int j = SIZE - 1; j >= 0; j--){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void swap_numbers(vector<vector<int>>& matrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = i + 1; j < SIZE; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

}

void rotate90(vector<vector<int>>& matrix){

    vector<vector<int>> result(SIZE, vector<int>(SIZE));

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            result[j][SIZE - i - 1] = matrix[i][j];
        }
    }

    matrix = result;

}

bool isSymmetric(vector<vector<int>>& matrix) {  
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++) 
            if (matrix[i][j] != matrix[j][i]) 
                return false; 
    return true; 
} 

void fill_new_Matrix(vector<vector<int>>& newMatrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE + 1; j++){
            newMatrix[i][j] = (rand() % 100);
        }
    }

}

void print_new_matrix(const vector<vector<int>>& newMatrix){

    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE1; j++){
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

}

vector<vector<int>> transpose_matrix(vector<vector<int>>& newMatrix){

    vector<vector<int>> transposeMatrix(SIZE1, vector<int>(SIZE));

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE1; j++){
            transposeMatrix[j][i] = newMatrix[i][j];
        }
    }

    return transposeMatrix;

}

void print_transpose_matrix(const vector<vector<int>>& matrix){

    for (int i = 0; i < SIZE1; i++){
        for (int j = 0; j < SIZE; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main (){
    srand(time(nullptr));

    vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
    vector<vector<int>> newMatrix(SIZE, vector<int>(SIZE1));

    filled_matrix(matrix);
    cout << "Matrix: " << endl;
    print_matrix(matrix);

    cout << "Min elements in the columns: ";
    find_min_elements_in_columns(matrix);

    cout << "Max elements in the columns: ";
    find_max_elements_in_columns(matrix); 

    cout << "Min elements in the rows: ";
    find_min_elements_in_rows(matrix);

    cout << "Max elements in the rows: ";
    find_max_elements_in_rows(matrix); 

    cout << "Matrix from right corner from up to down: " << endl;
    print_matrix_from_right_corner_up_and_down(matrix); 

    cout << "Matrix from left to right: " << endl;
    print_matrix_from_right_corner_from_left_to_right(matrix);

    swap_numbers(matrix);
    cout << "Matrix whose values are changed relative to the main diagonal: " << endl;
    print_matrix(matrix);

    rotate90(matrix);
    cout << "Rotated matrix on 90 degrees: " << endl;
    print_matrix(matrix);

    if(isSymmetric(matrix) == true){
        cout << "Is symetric!" << endl;
    }
    else {
        cout << "Isn't symetric!" << endl;
    }

    fill_new_Matrix(newMatrix);
    cout << "New matrix 5x6 (before): " << endl;
    print_new_matrix(newMatrix);

    vector<vector<int>> transpose = transpose_matrix(newMatrix);
    
    cout << "New matrix 5x6 (after transposing): " << endl;
    print_transpose_matrix(transpose);

    cout << "It's practice with matrix!" << endl;

    return 0;
}
