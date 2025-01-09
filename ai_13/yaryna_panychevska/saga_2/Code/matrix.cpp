#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Знаходження найбільших і найменших елементів в стовпцях матриці
void function_1(const int matrix[5][5], int max_value_array[5], int min_value_array[5]) {

    for (int j = 0; j < 5; j++) {

        int max_value = matrix[0][j];
        int min_value = matrix[0][j];

        for (int i = 1; i < 5; i++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
            }
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
        }
        max_value_array[j] = max_value;
        min_value_array[j] = min_value;
    }
}

//Пошук найбільшого та найменшого елементу в матриці (оскільки в нас є масиви з найбільшими/найменшими елементами, то будемо працювати з ними)
void function_2(int max_value_array[5], int min_value_array[5], int& max_num, int& min_num) {

    max_num = max_value_array[0];
    min_num = min_value_array[0];

    for (int i = 1; i < 5; i++) {

        if (max_num < max_value_array[i]) {
            max_num = max_value_array[i];
        }
        if (min_num > min_value_array[i]) {
            min_num = min_value_array[i];
        }
    }
}

//Обернення значення матриці відносно побічної діагоналі
void function_5(const int matrix[5][5], int rotated[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            rotated[i][j] = matrix[5 - j - 1][5 - i - 1];
        }
    }
}

//Поворот матриці на 90 градусів
void function_6(const int new_matrix[5][5], int rotated_matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            rotated_matrix[j][4 - i] = new_matrix[i][j];
        }
    }
}

//Перевірка на симетричність матриць
bool function_7(const int matrix[5][5]) {

    int transpose[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != transpose[i][j]) {
                return false;
            }
        }
    }
    return true;
}

//Транспонування матриці 5x6
void function_8(int matrix[5][6], int transpose[6][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

//Додавання двох матриць
void function_9(const int matr1[5][5], const int matr2[5][5], int sum_matr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sum_matr[i][j] = matr1[i][j] + matr2[i][j];
        }
    }
}

//Множення двох матриць
void function_10(const int matr1[5][5], const int matr2[5][5], int mult_matr[5][5]) {

    int cols1 = 5, rows2 = 5;

    if (cols1 != rows2)//Формальна перевірка 
    {
        cout << "Matrix multiplication is not possible!" << endl;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mult_matr[i][j] = 0;
            for (int n = 0; n < 5; n++) {
                mult_matr[i][j] += matr1[i][n] * matr2[n][j];
            }
        }
    }
}

//Обчислення визначника
int function_11(const int matr[5][5], int n) {

    int determinant = 0;
    int submatr[5][5];

    if (n == 1) {
        determinant = matr[0][0];
    }
    else if (n == 2) {
        determinant = (matr[0][0] * matr[1][1]) - (matr[1][0] * matr[0][1]);
    }
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0; // Рядок для підматриці
            for (int i = 1; i < n; i++) { // Починаємо з другого рядка
                int subj = 0; // Стовпець для підматриці
                for (int j = 0; j < n; j++) {
                    if (j == x)
                    {
                        continue;// Пропускаємо стовпець
                    } 
                    submatr[subi][subj] = matr[i][j];
                    subj++;
                }
                subi++;
            }
            determinant += pow(-1, x) * matr[0][x] * function_11(submatr, n - 1);
        }

    }
    return determinant;
}

int main() {

    int matrix[5][5] = {
        { 12, 7, -3, 8, 5 },
        { 6, 14, 0, -7, 9 },
        { 4, -2, 11, 3, -1 },
        { 10, 5, 6, 13, -4 },
        { 7, 8, -9, 2, 0 }
    };

    int new_matrix[5][5] = {
        {1, 7, 3, 2, 5},
        {7, 4, 6, 8, 9},
        {3, 6, 2, 4, 7},
        {2, 8, 4, 5, 3},
        {5, 9, 7, 3, 1}
    };

    int matrix1[5][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };

    int max_value_array[5];
    int min_value_array[5];
    function_1(matrix, max_value_array, min_value_array);

    cout << "The largest number of each column\n";
    for (int i = 0; i < 5; i++) {
        cout << "Column " << i + 1 << ": " << max_value_array[i] << endl;
    }

    cout << "The least number of each column\n";
    for (int i = 0; i < 5; i++) {
        cout << "Column " << i + 1 << ": " << min_value_array[i] << endl;
    }

    int max_num, min_num;
    function_2(max_value_array, min_value_array, max_num, min_num);

    cout << "The largest number of whole matrix: " << max_num << endl;
    cout << "The least number of whole matrix: " << min_num << endl;

    cout << "Checking for symmetric two matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << "\t\t";
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }


    if (function_7(new_matrix)) {
        cout << "First matrix is symmetric." << endl;
    }
    else {
        cout << "First matrix is not symmetric." << endl;
    }

    if (function_7(matrix)) {
        cout << "Second matrix is symmetric." << endl;
    }
    else {
        cout << "Second matrix is not symmetric." << endl;
    }

    cout << "Matrix(5x6) before and after transpose:\n";

    int new_matrix1[6][5];
    function_8(matrix1, new_matrix1);

    cout << "Original Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << setw(4) << matrix1[i][j];
        }
        cout << endl;
    }

    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix1[i][j];
        }
        cout << endl;
    }

    cout << "Matrix before and after being rotated by 90 degree:\n";

    int rotated_matrix[5][5];
    function_6(new_matrix, rotated_matrix);

    cout << "Original Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nRotated Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << rotated_matrix[i][j];
        }
        cout << endl;
    }

    cout << "Transposing a matrix along the non-main diagonal:\n";

    int rotated_matrix1[5][5];
    function_5(matrix, rotated_matrix1);


    cout << "Original Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nRotated Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << rotated_matrix1[i][j];
        }
        cout << endl;
    }

    cout << "The newly formed matrix after adding the other two:\n";

    int sum_matrix[5][5];
    function_9(matrix, new_matrix, sum_matrix);

    cout << "Matrix 1:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "\nMatrix 2:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << endl;
    }
    cout << "\nResult:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << sum_matrix[i][j];
        }
        cout << endl;
    }

    cout << "The newly formed matrix after multiplying the other two:\n";

    int mult_matrix[5][5];
    function_10(new_matrix, new_matrix, mult_matrix);

    cout << "Matrix 1:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nMatrix 2:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nResult:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << mult_matrix[i][j];
        }
        cout << endl;
    }

    cout << "Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << new_matrix[i][j];
        }
        cout << endl;
    }

    int n = 5;
    int determinant = function_11(new_matrix, n);
    cout << "Determinant:\n" << determinant << endl;

    return 0;
}

//Якщо Ви мій ревювер, то співчуваю :)