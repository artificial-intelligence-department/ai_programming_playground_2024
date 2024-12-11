//матриця 5*5
#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

//знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
void find_max_in_columns(int matrix[ROWS][COLS]) {
    cout << "Максимальні елементи у стовпцях: ";
    for (int j = 0; j < COLS; j++) {
        int max_val = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] > max_val) max_val = matrix[i][j];
        }
        cout << max_val << " ";
    }
    cout << endl;
}

//знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
void find_min_in_columns(int matrix[ROWS][COLS]) {
    cout << "Мінімальні елементи у стовпцях: ";
    for (int j = 0; j < COLS; j++) {
        int min_val = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] < min_val) min_val = matrix[i][j];
        }
        cout << min_val << " ";
    }
    cout << endl;
}

//знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
void find_max_in_rows(int matrix[ROWS][COLS]) {
    cout << "Максимальні елементи у рядках: ";
    for (int i = 0; i < ROWS; i++) {
        int max_val = matrix[i][0];
        for (int j = 1; j < COLS; j++) {
            if (matrix[i][j] > max_val) max_val = matrix[i][j];
        }
        cout << max_val << " ";
    }
    cout << endl;
}

//знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
void find_min_in_rows(int matrix[ROWS][COLS]) {
    cout << "Мінімальні елементи у рядках: ";
    for (int i = 0; i < ROWS; i++) {
        int min_val = matrix[i][0];
        for (int j = 1; j < COLS; j++) {
            if (matrix[i][j] < min_val) min_val = matrix[i][j];
        }
        cout << min_val << " ";
    }
    cout << endl;
}

//вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
void print_from_bottom_right_up_down(int matrix[ROWS][COLS]) {
    cout << "Матриця з правого нижнього кута вгору по стовпцях:\n";
    for (int j = COLS - 1; j >= 0; j--) {
        for (int i = ROWS - 1; i >= 0; i--) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//вивести матрицю з нижнього правого кута з ліва на право, з верху вниз 
void print_from_bottom_right_left_to_right(int matrix[ROWS][COLS]) {
    cout << "Матриця з правого нижнього кута зліва направо:\n";
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = COLS - 1; j >= 0; j--) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
void transpose_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = i + 1; j < COLS; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

//зробити поворот матриці на 90 градусів 
void rotate_matrix_90(int matrix[ROWS][COLS]) {
    transpose_matrix(matrix);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS / 2; j++) {
            swap(matrix[i][j], matrix[i][COLS - 1 - j]);
        }
    }
}

//перевірити чи матриця симетрична 
bool is_symmetric(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}

//далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
void transpose_nonsquare_matrix(int matrix[5][6], int result[6][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout << "Початкова матриця:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    find_max_in_columns(matrix); // Завдання 1
    find_min_in_columns(matrix); // Завдання 2
    find_max_in_rows(matrix);    // Завдання 3
    find_min_in_rows(matrix);    // Завдання 4
    print_from_bottom_right_up_down(matrix); // Завдання 5
    print_from_bottom_right_left_to_right(matrix); // Завдання 6

    cout << "\nМатриця після повороту на 90 градусів:\n";
    rotate_matrix_90(matrix); // Завдання 8
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }

    cout << "\nЧи є матриця симетричною? " << (is_symmetric(matrix) ? "Так" : "Ні") << endl; // Завдання 9

    int matrix5x6[5][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };

    int transposed[6][5];
    transpose_nonsquare_matrix(matrix5x6, transposed); // Завдання 10

    cout << "\nПочаткова матриця 5x6:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << setw(3) << matrix5x6[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nТранспонована матриця 6x5:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(3) << transposed[i][j] << " ";
        }
        cout << endl;
    };

    return 0;
}
