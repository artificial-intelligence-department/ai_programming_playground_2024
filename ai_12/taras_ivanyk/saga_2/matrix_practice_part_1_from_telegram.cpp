// part 1 from telegram, from Zagorodniy

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

const int row = 5;
const int col = 5;

void create_matrix(int row, int col, int** matrix) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = rand() % 10;  // Генеруємо числа від 0 до 99
        }
    }
}

void print_matrix(int row, int col, int** matrix) {
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void find_max_elements_in_col(int row, int col, int* arr_col, int** matrix) {
    for (int j = 0; j < col; ++j) {
        int max_element = matrix[0][j];
        for (int i = 1; i < row; ++i) {
            if (matrix[i][j] > max_element) {
                max_element = matrix[i][j];
            }
        }
        arr_col[j] = max_element;  
    }
}

void min_elemnts_col(int row, int col, int* arr_col, int** matrix){
    for(int j = 0; j < col; ++j){
        int min_element = matrix[0][j];
        for(int i = 1; i < row; ++i){         // start from i = 1, because we already have min_element = matrix[0][j]
            if(matrix[i][j] < min_element){
                min_element = matrix[i][j];
            }
        }
        arr_col[j] = min_element;
    }
}

void max_elements_row(int row, int col, int* arr_row, int** matrix){
    for(int i = 0; i < row; ++i){
        int max_elements = matrix[i][0];
        for(int j = 1; j < col; ++j){
            if(matrix[i][j] > max_elements){
                max_elements = matrix[i][j];
            }                                    // max in row
        }
        arr_row[i] = max_elements;
    }
}

void min_elements_row(int row, int col, int* arr_row, int** matrix){
    for(int i = 0; i < row; ++i){
        int min_elements = matrix[i][0];
        for(int j = 1; j < col; ++j){
            if(matrix[i][j] < min_elements){
                min_elements = matrix[i][j];
            }                                    // max in row
        }
        arr_row[i] = min_elements;
    }
}
// Different outputs of matrix:

void print_matrix_from_right_down_angle_and_up_by_cols(int row, int col, int** matrix){
    for (int j = col - 1; j >= 0; --j){
        for (int i = row - 1; i >= 0; --i){
            cout << setw(3) << matrix[i][j] << " ";                 // output cols up
        }
        cout << endl;
    }
}

// function*
void print_matrix_from_right_down_angle_and_down_by_cols(int row, int col, int** matrix){
    for (int j = col - 1; j >= 0; --j){
        for (int i = 0; i < row; ++i){
            cout << setw(3) << matrix[i][j] << " ";                 // output cols down  
        }
        cout << endl;
    }
}

// continue
void print_matrix_from_right_down_angle_from_left_to_right(int row, int col, int** matrix){
    for (int i = col - 1; i >= 0; --i){
        for (int j = col - 1; j >= 0; --j){
            cout << setw(3) << matrix[i][j] << " ";                 // output left-right
        }
        cout << endl;
    }
}

void print_matrix_from_right_down_angle_from_up_to_down(int row, int col, int** matrix){
    for (int j = col - 1; j >= 0; --j){
        for (int i = 0; i < row; ++i){
            cout << setw(3) << matrix[i][j] << " ";                 // output up-down (the same as function*)
        }
        cout << endl;
    }
}

void print_matrix_and_turn_by_diagonal(int row, int col, int** matrix){    // turn matrix by diagonal (1,1) - (5,5)
    for(int j = 0; j < row; ++j){
        for(int i = 0; i < col; ++i){
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print_matrix_turned_by_90_deegres(int row, int col, int** matrix){
    for(int i = 0; i < row; ++i){
        for(int j = col - 1; j >= 0; --j){
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_matrix_simetric(int row, int col, int** matrix){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(matrix[i][j] != matrix[j][i]){
            return false;
            }
        }
    }
    return true;
}

// from here functions with static array

void create_matrix_5_na_6(int r1, int c1, int matrix_static_1[5][6]){
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){                     // Заповнення двовимірного статичного масиву
            matrix_static_1[i][j] = rand() % 30;
        }
    }
}

void print_matrix_5_na_6(int r1, int c1, int matrix_static_1[5][6]){
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            cout << setw(3) << matrix_static_1[i][j] << " ";
        }
        cout << endl;
    }
}

void print_transponate_matrix_5_na_6(int r1, int c1, int matrix_static_1[5][6]){
    for(int j = 0; j < c1; ++j){
        for(int i = 0; i < r1; ++i){
            cout << setw(3) << matrix_static_1[i][j] << " ";
        }
        cout << endl;
    }
}

void create_matrix_5_na_6_second(int r2, int c2, int matrix_static_2[6][5]){
    for(int i = 0; i < r2; ++i){
        for(int j = 0; j < c2; ++j){                     // Заповнення двовимірного статичного масиву
            matrix_static_2[i][j] = rand() % 30;
        }
    }
}

void print_matrix_5_na_6_second(int r2, int c2, int matrix_static_2[6][5]){
    for(int i = 0; i < r2; ++i){
        for(int j = 0; j < c2; ++j){
            cout << setw(3) << matrix_static_2[i][j] << " ";
        }
        cout << endl;
    }
}

void print_sum_of_matrix(int r1, int c1, int r2, int c2,  int matrix_static_1[5][6], int matrix_static_2[6][5]){
    for(int i = 0 ; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            cout << setw(3) << matrix_static_1[i][j] + matrix_static_2[i][j] << " ";
        }
        cout << endl;
    }
}

void multi_of_two_matrix(int r1, int c1, int r2, int c2,  int matrix_static_1[5][6], int matrix_static_2[6][5], int result[5][5]){
    if (c1 != r2) {
        cout << "Error: Matrices cannot be multiplied due to incompatible dimensions." << endl;
        return;
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {  // `c1` або `r2` однакові
                result[i][j] += matrix_static_1[i][k] * matrix_static_2[k][j];
            }
        }
    }
}

void print_multi_of_two_matrix(int r1, int c1, int r2, int c2,  int matrix_static_1[5][6], int matrix_static_2[6][5], int result[5][5]){
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c2; ++j){
            cout << setw(3) << result[i][j] << " ";
        }
        cout << endl;
    }
}

// change 2 and 3 column in matrix_static_1:

void print_change_columns_2_3(int r1, int c1, int matrix_static_1[5][6]){
    for(int i = 0; i < r1; ++i){
        swap(matrix_static_1[i][2], matrix_static_1[i][3]);
    }

    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            cout << setw(3) << matrix_static_1[i][j] << " ";
        }
        cout << endl;
    }
       
}

void find_maximum_in_matrix_1(int r1, int c1, int matrix_static_1[5][6]){
    int max_element = matrix_static_1[0][0];
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            if(matrix_static_1[i][j] > max_element){
                max_element = matrix_static_1[i][j];
            }
        }
    }
    cout << endl << "Maximum element in matrix 1 = " << max_element << endl;
}

void find_minimum_in_matrix_1(int r1, int c1, int matrix_static_1[5][6]){
    int min_element = matrix_static_1[0][0];
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            if(matrix_static_1[i][j] < min_element){
                min_element = matrix_static_1[i][j];
            }
        }
    }
    cout << endl << "Minimum element in matrix 1 = " << min_element << endl;
}


// Determinat for 3*3:

void create_matrixD(int rowD, int colD, int matrixD[3][3]){
    for(int i = 0; i < rowD; ++i){
        for(int j = 0; j < colD; ++j){                     // Заповнення двовимірного статичного масиву
            matrixD[i][j] = rand() % 9;
        }
    }
}

void print_matrixD(int rowD, int colD, int matrixD[3][3]){
    for(int i = 0; i < rowD; ++i){
        for(int j = 0; j < colD; ++j){                     // Заповнення двовимірного статичного масиву
            cout << setw(3) << matrixD[i][j] << " ";
        }
        cout << endl;
    }
}

void determinat_for_matrix_DETERMINATOR(int rowD, int colD, int matrixD[3][3]){
    int sum = 0;

    for(int i = 0; i < rowD; ++i){
        for(int j = 0; j < colD; ++j){
            sum += matrixD[0][0] * matrixD[1][1] * matrixD[2][2] + matrixD[1][0] * matrixD[0][2] * matrixD[2][1] + matrixD[2][0] * matrixD[0][1] * matrixD[1][2];
            sum -= matrixD[0][2] * matrixD[1][1] * matrixD[2][0] + matrixD[0][0] * matrixD[2][1] * matrixD[1][2] + matrixD[1][0] * matrixD[0][1] * matrixD[2][2];
        }
    }
    cout << endl << "Determinat of matrix 3*3 = " << sum << endl;
}

// find exact number at the matrix_static_1:

int exact_number_in_matrix(int num, int r1, int c1, int matrix_static_1[5][6]){
    if(num < 0 || num >= r1 * c1){
        cout << "Error, you enter wrong number [not from diapasone] " << endl;
        return -1;
    }

    int row = num / c1;
    int col = num % c1;
    return matrix_static_1[row][col];
}

void sum_of_all_elements_in_matrix_1(int row, int col, int matrix_static_1[5][6]){
    int sum = 0;
    double count = 0.0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            sum += matrix_static_1[i][j];
            count++;
        }
    }
    cout << endl << "Sum of all elements in matrix 1 = " << sum << endl;
    cout << endl <<"Average value of all elements = " << double(sum) / count << endl;
}

// from here i do everything with generate matrix: 
void generate_random_matrix(int rand_row, int rand_col, int** matrix_rand){
    srand(static_cast<unsigned>(time(nullptr)));

    for(int i = 0; i < rand_row; ++i){
        for(int j = 0; j < rand_col; ++j){
            matrix_rand[i][j] = rand() % (rand_row * rand_col); 
        }
    }
}

void print_random_matrix(int rand_row, int rand_col, int** matrix_rand){
    for(int i = 0; i < rand_row; ++i){
        for(int j = 0; j < rand_col; ++j){
            cout << setw(3) << matrix_rand[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}

void find_elements_on_diagonale(int rand_row, int rand_col, int** matrix_rand){
    if(rand_row != rand_col){
        cout << "Error, random generate matrix is not square, so it doesn't have main diagonale( " << endl; 
        return;
    }
    cout << endl << "Elements on the main diagonale for random generate matrix are: " << endl;
    for(int i = 0; i < rand_row; ++i){
        cout << matrix_rand[i][i] << " ";
    }
    cout << endl;
}

void find_row_with_max_sum(int rand_row, int rand_col, int** matrix_rand){
    cout << endl;
    
    int max_sum = INT_MIN;
    int row_index = -1;

    for (int i = 0; i < rand_row; ++i) {
        int current_sum = 0;
        for (int j = 0; j < rand_col; ++j) {
            current_sum += matrix_rand[i][j]; 
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            row_index = i;
        }
    }
    cout << "Row with maximum sum in generate matrix: " << row_index + 1 << endl; 
    cout << "Maximum sum: " << max_sum << endl;

    cout << "Elements of this row: ";
    for (int j = 0; j < rand_col; ++j) {
        cout << matrix_rand[row_index][j] << " ";
    }
    cout << endl;
}

int count_exact_number(int number, int rand_row, int rand_col, int** matrix_rand) { 
    int count = 0;                                          
    for (int i = 0; i < rand_row; ++i) {               // help function to know, how many times is exact number repeats
        for (int j = 0; j < rand_col; ++j) {
            if (matrix_rand[i][j] == number) {
                count++;
            }
        }
    }
    return count;
}

void repeat_number(int rand_row, int rand_col, int** matrix_rand){
    int max_repeats = matrix_rand[0][0];
    int max_count = 0;

    for(int i = 0; i < rand_row; ++i){
        for(int j = 0; j < rand_col; ++j){
            int cur_count = count_exact_number(matrix_rand[i][j], rand_row, rand_col, matrix_rand);

            if(cur_count > max_count){
                max_count = cur_count;
                max_repeats = matrix_rand[i][j];
            }
        }
    }
    cout << endl << "The most repeated number: " << max_repeats << endl;
    cout << "Repeats " << max_count << " times." << endl;
}

void search_even_numbers(int rand_row, int rand_col, int** matrix_rand){
    int count_is_even = 0;

    cout << endl << "Even numbers in this generated matrix are: " << endl;
    for(int i = 0; i < rand_row; ++i){
        for(int j = 0; j < rand_col; ++j){
            if(matrix_rand[i][j] % 2 == 0){
                count_is_even++;
                cout << matrix_rand[i][j] << " "; 
            }
        }
    }
    cout << endl << "There are " << count_is_even << " even numbers in this generated matrix." << endl;
    
    cout << endl;
}

void print_transpone_matrix_that_was_randomly_generated(int rand_row, int rand_col, int** matrix_rand){
    cout << "Transpone matrix: "<< endl;

    for(int j = 0; j < rand_row; ++j){
        for(int i = 0; i < rand_col; ++i){
            cout << setw(3) << matrix_rand[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    int arr_col[col];
    int arr_row[row];

    int** matrix = new int*[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new int[col];
    }

    create_matrix(row, col, matrix);
    cout << "Generated Matrix:" << endl;
    print_matrix(row, col, matrix);
    cout << endl;

    find_max_elements_in_col(row, col, arr_col, matrix);

    cout << "Max elements in each column:" << endl;
    for (int j = 0; j < col; ++j) {                                    // max in col
        cout << "Column " << j + 1 << ": " << arr_col[j] << endl;
    }
    cout << endl;

    min_elemnts_col(row, col, arr_col, matrix);

    cout << "Min elements in each column:" << endl;
    for (int j = 0; j < col; ++j) {
        cout << "Column " << j + 1 << ": " << arr_col[j] << endl;    // min in col
    }
    cout << endl;

    max_elements_row(row, col, arr_row, matrix);

    cout << endl << "Max elements in each row: " << endl;
    for(int i = 0; i < row; ++i){
        cout << "Row " << i + 1 << ": " << arr_row[i] << endl;
    }

    min_elements_row(row, col, arr_row, matrix);

    cout << endl;
    cout << "Min elements in each row: " << endl;
    for(int i = 0; i < row; ++i){
        cout << "Row " << i + 1 << ": " << arr_row[i] << endl;
    }
    cout << endl;


    // first 4 exercises were done, now continue from different outputs of matrix
    cout << "Output of matrix from right down angle up by columns: \n";
    print_matrix_from_right_down_angle_and_up_by_cols(row, col, matrix);
    cout << endl;
    
    cout << "Output of matrix from right down angle down by columns: \n";
    print_matrix_from_right_down_angle_and_down_by_cols(row, col, matrix);
    cout << endl;

    cout << "Output of matrix from right down from left to right: \n";
    print_matrix_from_right_down_angle_from_left_to_right(row, col, matrix);
    cout << endl;

    cout << "Output of matrix from right down from up to down: \n";
    print_matrix_from_right_down_angle_from_up_to_down(row, col, matrix);
    cout << endl;

    cout << "Output of matrix turned by diagonal (1,1)-(5,5): \n";
    print_matrix_and_turn_by_diagonal(row, col, matrix);
    cout << endl;

    cout << "Output of matrix turned by 90 deegres to right \n";
    print_matrix_turned_by_90_deegres(row, col, matrix);
    cout << endl;

    if(is_matrix_simetric(row, col, matrix)){
        cout << "Matrix is simetric " << endl;
    } else{
        cout << "Matrix is not simetric" << endl;
    }

// first matrix:
    int r1 = 5;
    int c1 = 6;
    int matrix_static_1[5][6];

    create_matrix_5_na_6(r1, c1, matrix_static_1);

    cout << endl << "Matrix 5 * 6, not transponated: \n";
    print_matrix_5_na_6(r1, c1, matrix_static_1);
    cout << endl;

    cout << endl << "Matrix 5 * 6 transponated: \n";
    print_transponate_matrix_5_na_6(r1, c1, matrix_static_1);
    cout << endl;

// second matrix:
    int r2 = 6;
    int c2 = 5;
    int matrix_static_2[6][5];

    create_matrix_5_na_6_second(r2, c2, matrix_static_2);

    cout << endl << "First matrix: \n";
    print_matrix_5_na_6(r1, c1, matrix_static_1);
    cout << endl;

    cout << endl << "Second matrix: \n";
    print_matrix_5_na_6_second(r2, c2, matrix_static_2);
    cout << endl;

    cout << "Sum of two matrix: " << endl;
    print_sum_of_matrix(r1, c1, r2, c2, matrix_static_1, matrix_static_2);
    cout << endl;

    int result[5][5];
    cout << endl << "Multiplication of 2 matrix: \n";
    multi_of_two_matrix(r1, c1, r2, c2, matrix_static_1, matrix_static_2, result);
    print_multi_of_two_matrix(r1, c1, r2, c2, matrix_static_1, matrix_static_2, result);
    cout << endl;

    cout << endl << "Matrix_1 with changed columns 3 and 4: \n";
    print_change_columns_2_3(r1, c1, matrix_static_1);
    cout << endl;

    find_maximum_in_matrix_1(r1, c1, matrix_static_1);
    find_minimum_in_matrix_1(r1, c1, matrix_static_1);

    int rowD = 3;
    int colD = 3;
    int matrixD[3][3];

    create_matrixD(rowD, colD, matrixD);
    cout << "Matrix 3*3, we want to find determinator of this matrix \n";
    print_matrixD(rowD, colD, matrixD);
    determinat_for_matrix_DETERMINATOR(rowD, colD, matrixD);
    cout << endl;

    cout << "Matrix were you would search exact value of element by number: " << endl;
    print_matrix_5_na_6(r1, c1, matrix_static_1);
    cout << endl;

    int num;
    cout << "Enter number of element from 0 to 29 and I'll return the value of this element in matrix: " << endl;
    cin >> num;

    int value = exact_number_in_matrix(num, r1, c1, matrix_static_1);
    if(value != -1) { cout << endl << "Value of element with number you entered = " << value << endl; }

    sum_of_all_elements_in_matrix_1(r1, c1, matrix_static_1);

// dynamic memory for generating random matrix for function that search elements on main diagonale
    int rand_row = rand() % 5 + 1;
    int rand_col = rand() % 5 + 1;           // rand matrix with size from 1*1 to 5*5
    
    int** matrix_rand = new int*[rand_row];
    for(int i = 0; i < rand_row; ++i){
        matrix_rand[i] = new int[rand_col];
    }

    generate_random_matrix(rand_row, rand_col, matrix_rand);

    cout << endl << "Generate random matrix: " << endl;
    print_random_matrix(rand_row, rand_col, matrix_rand);

    find_elements_on_diagonale(rand_row, rand_col, matrix_rand);

    find_row_with_max_sum(rand_row, rand_col, matrix_rand);

    repeat_number(rand_row, rand_col, matrix_rand);

    search_even_numbers(rand_row, rand_col, matrix_rand);

    print_transpone_matrix_that_was_randomly_generated(rand_row, rand_col, matrix_rand);

    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < rand_row; ++i){
        delete[] matrix_rand[i];
    }
    delete[] matrix_rand;

    return 0;
}
