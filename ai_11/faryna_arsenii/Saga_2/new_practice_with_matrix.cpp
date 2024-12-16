/* Ініціалізація матриці: Заповнення статичного двовимірного масиву.
- Додавання двох матриць: Елемент за елементом додаються елементи двох матриць.
- Множення двох матриць: Класичний алгоритм множення матриць.
- Транспонування матриці: Обмін рядків і стовпців місцями.
- Пошук максимуму/мінімуму в матриці.
- Обчислення детермінанта (для квадратних матриць).
- Пошук конкретного елемента в матриці
- Пошук мінімального елемента
- Пошук максимального елемента
- Пошук суми всіх елементів
- Пошук середнього значення
- Пошук діагональних елементів
- Пошук рядка з максимальною сумою
- Пошук числа, що повторюється найбільше
- Пошук парних елементів
- Пошук транспонованої матриці
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

const int length = 3;

void create_matrix(int** matrix){

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            matrix[i][j] = (1 + rand() % 10);
        }
    }

}

void print_matrix(int** matrix){

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void add_two_matrix(int** result, int** matrix, int** matrix1){

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            result[i][j] = matrix[i][j] + matrix1[i][j]; 
        }
    }

}

void multiply_matrix(int** result, int** matrix, int** matrix1){

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            for (int k = 0; k < length; k++){
                result[i][j] += (matrix[i][j] * matrix1[j][i]);
            }
        }
    }

}

void transpose_matrix(int** result, int** matrix){

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            result[j][i] = matrix[i][j];
        }
    }

}

double determinant(int** matrix){

    double det = 1.0;
    for (int i = 0; i < length; i++){
        int pivot = 1;
        for (int j = i + 1; j < length; j++){
            if (abs(matrix[j][i]) > abs(matrix[pivot][i])){
                pivot = j;
            }
        }
        if (pivot != i){
            swap(matrix[i], matrix[pivot]);
            det *= -1;
        }
        if (matrix[i][i] == 0){
            return 0;
        }
        det *= matrix[i][i];
        for (int j = i + 1; j < length; j++){
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i + 1; k < length; k++){
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    return det;

}

int sum_of_all_elements(int** matrix){

    int sum;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            sum += matrix[i][j];
        }
    }

    return sum;

}

void find_diagonal_elements(int** matrix){

    for (int i = 0; i < length; i++){
        cout << matrix[i][i] << " ";
    }

}

int main (){

    srand(time(nullptr));

    // first matrix
    int** matrix = new int*[length];

    for (int i = 0; i < length; i++){
        matrix[i] = new int[length];
    }

    // second matrix
    int** matrix1 = new int*[length];
    
    for (int i = 0; i < length; i++){
        matrix1[i] = new int[length];
    }

    // result matrix
    int** result = new int*[length];

    for (int i = 0; i < length; i++){
        result[i] = new int[length];
    }

    create_matrix(matrix);
    cout << "First matrix: " << endl;
    print_matrix(matrix);

    create_matrix(matrix1);
    cout << "Second matrix: " << endl;
    print_matrix(matrix1);

    add_two_matrix(result, matrix, matrix1);
    cout << "First matrix + second matrix = " << endl;
    print_matrix(result);

    multiply_matrix(result, matrix, matrix1);
    cout << "First matrix * second matrix = " << endl;
    print_matrix(result);

    transpose_matrix(result, matrix);
    cout << "Transpose matrix: " << endl;
    print_matrix(result);

    double det = determinant(matrix);
    cout << "Determinant: " << det << endl;

    int sum = sum_of_all_elements(matrix);
    cout << "Sum of all elements: " << sum << endl;

    double average_value = static_cast<double>(sum) / (length * length);
    cout << setprecision(2) << "Average value: " << average_value << endl;

    cout << "Diagonal elements: ";
    find_diagonal_elements(matrix1);

    for (int i = 0; i < length; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < length; i++){
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < length; i++){
        delete[] result[i]; 
    }
    delete[] result;

    return 0;
}