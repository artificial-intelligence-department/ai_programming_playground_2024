#include <iostream>

using namespace std;
const int n = 5;
const int c = 6;

void print_result(int result[n]){
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
} 

void search_max_el_in_colums(int matrix[n][n], int result[n]){
    for (int i = 0; i < n; i++)
    {
        int max_el = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][i] > max_el)
            {
                max_el = matrix[j][i];
            }
            
        }
        result[i] = max_el;
    }
    print_result(result);
}

void search_min_el_in_colums(int matrix[n][n], int result[n]){
    for (int i = 0; i < n; i++)
    {
        int min_el = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][i] < min_el)
            {
                min_el = matrix[j][i];
            }
            
        }
        result[i] = min_el;
    }
    print_result(result);
}

void search_max_el_in_ryad (int matrix[n][n], int result[n] ){
    for (int i = 0; i < n; i++)
    {
        int max_el = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > max_el)
            {
                max_el = matrix[i][j];
            }
            
        }
        result[i] = max_el;
    }
    print_result(result);
}
void search_min_el_in_ryad(int matrix[n][n], int result[n] ){
    for (int i = 0; i < n; i++)
    {
        int min_el = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < min_el)
            {
                min_el = matrix[i][j];
            }
            
        }
        result[i] = min_el;
    }
    
    print_result(result);
}
void print_matrix(int matrix[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}
void print_matrix_right_kut(int matrix[n][n]){
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << matrix[j][i] << " ";

        }
        cout << endl;
    }
    
}

void print_matrix_left_right ( int matrix[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
    
}

void matrix_inverted(int matrix[n][n]){
    int result[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = matrix[j][i];
        }
        
    }
    print_matrix(result);
}
void matrix_inverted_of_90(int matrix[n][n]){
    int result[n][n];
    int c = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[j][n - i - 1] = matrix[i][j];
            
        }
    }
    print_matrix(result);
}

bool semetric_matrix(int matrix[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
         if (matrix[i][j] != matrix[j][i])
         {
            return false;
         }
            
        }
    }
    return true;
}
void trans_matrix(int matrix[n][c]){
    int result[c][n];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }

    cout << "далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після" << endl;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int matrix [n][n] {
        {3, 8, 7, 1, 2},
        {6, 2, 4, 9, 5},
        {9, 5, 1, 6, 8},
        {4, 7, 3, 8, 2},
        {5, 6, 9, 3, 4}
    };
    int max_col[n];
    search_max_el_in_colums(matrix, max_col);
    int min_col[n];
    search_min_el_in_colums(matrix, min_col);
    int max_ryad[n];
    search_max_el_in_ryad(matrix, max_ryad);
    int min_ryad[n];
    search_min_el_in_ryad(matrix, min_ryad);
    cout << " вивести матрицю з нижнього правого кута вверх і вниз по стовпцям" << endl;
    print_matrix_right_kut(matrix);
    cout << "вивести матрицю з нижнього правого кута з ліва на право, з верху вниз " << endl;
    print_matrix_left_right(matrix);
    cout << "обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)" << endl;
    matrix_inverted(matrix);
    cout << "зробити поворот матриці на 90 градусів " << endl;
    matrix_inverted_of_90(matrix);
    cout << "перевірити чи матриця симетрична" << endl;
    if (!semetric_matrix(matrix))
    {
        cout << " Матриця не семетрична" << endl;
    }else{
        cout << " Матриця семетрична" << endl;
    }
    int matrix_trans[n][c]{
        {3, 8, 7, 1, 2, 6},
        {6, 2, 4, 9, 5, 8},
        {9, 5, 1, 6, 8, 0},
        {4, 7, 3, 8, 2, 3},
        {5, 6, 9, 3, 4, 1}
    };
    trans_matrix(matrix_trans);

    return 0;
}