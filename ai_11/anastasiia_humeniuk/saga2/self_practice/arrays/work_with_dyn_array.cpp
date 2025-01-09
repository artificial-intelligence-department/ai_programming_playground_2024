/*
- знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат done
- знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат done
- знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат done
- знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат done
- вивести матрицю з нижнього правого кута вверх і вниз по рядках done
- обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями) done
- зробити поворот матриці на 90 градусів done
- перевірити чи матриця симетрична done
- далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
- Пошук конкретного елемента в матриці done
- Пошук мінімального елемента done
- Пошук максимального елемента done
- Пошук суми всіх елементів done
- Пошук середнього значення done
- Пошук діагональних елементів done
- Пошук рядка з максимальною сумою done
- Пошук парних елементів done
- Пошук транспонованої матриці done
*/
#include <iostream>
#include <utility>

using namespace std;

int *findMaxInColumns(int **array, int size)
{
    int *result = new int[size];
    for (int j = 0; j < size; j++)
    {
        int maxElem = array[0][j];
        for (int i = 1; i < size; i++)
        {
            if (array[i][j] > maxElem)
            {
                maxElem = array[i][j];
            }
        }
        result[j] = maxElem;
    }
    return result;
}

int *findMinInColumns(int **array, int size)
{
    int *result = new int[size];
    for (int j = 0; j < size; j++)
    {
        int minElem = array[0][j];
        for (int i = 1; i < size; i++)
        {
            if (array[i][j] < minElem)
            {
                minElem = array[i][j];
            }
        }
        result[j] = minElem;
    }
    return result;
}

int *findMaxInRows(int **array, int size)
{
    int *result = new int[size];
    for (int i = 0; i < size; i++)
    {
        int maxElem = array[i][0];
        for (int j = 1; j < size; j++)
        {
            if (array[i][j] > maxElem)
            {
                maxElem = array[i][j];
            }
        }
        result[i] = maxElem;
    }
    return result;
}

int *findMinInRows(int **array, int size)
{
    int *result = new int[size];
    for (int i = 0; i < size; i++)
    {
        int minElem = array[i][0];
        for (int j = 1; j < size; j++)
        {
            if (array[i][j] < minElem)
            {
                minElem = array[i][j];
            }
        }
        result[i] = minElem;
    }
    return result;
}

void printMatrixRightDown(int **array, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = size - 1; j >= 0; j--)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printMirrorMatrix(int **array, int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSymetric(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] != array[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

void printTurnMatrix(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    { // Реверсування кожного рядка
        int start = 0;
        int end = size - 1;
        while (start < end)
        {

            int temp = array[i][start]; // Міняємо місцями елементи в рядку
            array[i][start] = array[i][end];
            array[i][end] = temp;
            start++;
            end--;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void printDynArray(int *result, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

}

pair<int, int> findElemInRows(int **array, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == element)
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int findMin(int **array, int size)
{
    int min = array[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] < min)
            {
                min = array[i][j];
            }
        }
    }
    return min;
}

int findMax(int **array, int size)
{
    int max = array[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
            }
        }
    }
    return max;
}

int findSum(int **array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           sum += array[i][j];
        }
    }
    return sum;
}
double findAvarage(int **array, int size)
{
    double sum = 0;
    double counter = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           sum += array[i][j];
           counter++;
        }
    }
    return sum/counter;
}

int *findDiagonal(int **array, int size)
{
    int *result = new int[size];
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
           if (i == j){
            result[j] = array[i][j];
           }
        }
    }
    return result;
}

int* findMaxSumInRows(int** array, int size) {
    int* result = new int[size];
    int max_suma = 0;
    int suma = 0;

    int maxRowIndex = 0;

    for (int i = 0; i < size; i++) {
        suma = 0;
        for (int j = 0; j < size; j++) {
            suma += array[i][j];
        }
        if (suma > max_suma) {
            max_suma = suma;
            maxRowIndex = i;
        }
    }

    for (int j = 0; j < size; j++) {
        result[j] = array[maxRowIndex][j];
    }

    return result;
}

void findParniNumbers(int **array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    int* result = new int[count];
    int resultIndex = 0;


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] % 2 == 0) {
                result[resultIndex++] = array[i][j];
            }
        }
    }
    for (int i = 0; i < count ; i++) {
        cout << result[i] <<" ";
    }

}

void printTransposedMatrix(int **array, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrix(int **matrix, int rows, int cols) { //перевантажена функція виводу для не квадратного масива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int **matrix, int rows, int cols) {

    int **transposed = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "Транспонована матриця:" << endl;
    printMatrix(transposed, cols, rows);

    for (int i = 0; i < cols; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;
}

int main()
{
    const int size = 5;

    int **matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    int initialData[size][size] = {
        {3, 8, 1, 9, 2},
        {4, 2, 7, 5, 3},
        {9, 5, 2, 6, 1},
        {1, 3, 8, 7, 4},
        {6, 4, 3, 8, 9}};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = initialData[i][j];
        }
    }

    int *result_1 = findMaxInColumns(matrix, size);

    cout << "Найбільші елементи в кожному стовпці: ";
    printDynArray(result_1, size);
    delete[] result_1;

    int *result_2 = findMinInColumns(matrix, size);
    cout << "Найменші елементи в кожному стовпці: ";
    printDynArray(result_2, size);
    delete[] result_2;
    
    int *result_3 = findMaxInRows(matrix, size);
    cout << "Найбільші елементи в кожному рядку: ";
    printDynArray(result_3, size);
    delete[] result_3;
    
    int *result_4 = findMinInRows(matrix, size);
    cout << "Найменші елементи в кожному рядку: ";
    printDynArray(result_4, size);
    delete[] result_4;
    
    cout << "Масив з правого нижнього кута по рядках: " << endl;
    printMatrixRightDown(matrix, size);

    cout << "Масив дзеркальний відносно діагоналі: " << endl;
    printMirrorMatrix(matrix, size);

    cout << "Чи є матриця симетричною: " << endl;
    cout << isSymetric(matrix, size) << endl;

    cout << "Обернута на 90 матриця: " << endl;
    printTurnMatrix(matrix, size);

    cout << "Знайти індекси елемента 2: " << endl;
    pair<int, int> result = findElemInRows(matrix, size, 2);
    if (result.first != -1)
    {
        cout << "Елемент знайдено на позиції: рядок "
             << result.first + 1
             << ", стовпець " << result.second + 1 << endl;
    }
    else
    {
        cout << "Елемент не знайдено." << endl;
    }

    cout << "Мінімальний елемент матриці: ";
    cout << findMin(matrix, size) << endl;

    cout << "Мaксимальний елемент матриці: ";
    cout << findMax(matrix, size) << endl;

    cout << "Cума елементів матриці: ";
    cout << findSum(matrix, size) << endl;

    cout << "Cереднє значення елементів матриці: ";
    cout << findAvarage(matrix, size) << endl;

    int *result_5 = findDiagonal(matrix, size);
    cout << "Діагональні елементи: ";
    printDynArray(result_5, size);
    delete[] result_5;
    
    int *result_6 = findMaxSumInRows(matrix, size);
    cout << "Найбільша сума елементів в рядку: ";
    printDynArray(result_6, size);
    delete[] result_6;
    
    
    cout << "Парні числа: ";
    findParniNumbers(matrix, size);
    cout << endl;

    cout << "Транспонована матриця: "<< endl;
    printTransposedMatrix(matrix, size);

    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    // для 5 на 6
    const int rows = 5;
    const int cols = 6;
    int **matrix2 = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix2[i] = new int[cols];
    }

    int initialData2[5][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2[i][j] = initialData2[i][j];
        }
    }

    // 5x6
    cout << "Оригінальна матриця 5x6:" << endl;
    printMatrix(matrix2, rows, cols);

    transposeMatrix(matrix2, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;

}
