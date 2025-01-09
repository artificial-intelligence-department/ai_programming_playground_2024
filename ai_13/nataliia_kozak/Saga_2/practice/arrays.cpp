#include <iostream>
#include <array>
#include <cmath>
using namespace std;
void print_matrix(int *matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        cout << endl;
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[j + i * (columns)] << ' ';
        }
    }
}
int main()
{
    int square_array[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> square_array[i][j];
        }
    }
    cout << endl
         << "You input: ";
    print_matrix(square_array[0], 5, 5);

    int max_in_column[5], max;
    for (int j = 0; j < 5; j++)
    {
        max = square_array[0][j];
        for (int i = 0; i < 5; i++)
        {
            if (max < square_array[i][j])
                max = square_array[i][j];
        }
        max_in_column[j] = max;
    }
    cout << endl
         << "Max in columns: ";
    print_matrix(max_in_column, 1, 5);
    int min_in_column[5], min;
    for (int j = 0; j < 5; j++)
    {
        min = square_array[0][j];
        for (int i = 0; i < 5; i++)
        {
            if (min > square_array[i][j])
                min = square_array[i][j];
        }
        min_in_column[j] = min;
    }
    cout << endl
         << "Min in columns: ";
    print_matrix(min_in_column, 1, 5);
    int min_in_row[5];
    for (int i = 0; i < 5; i++)
    {
        min = square_array[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (min > square_array[i][j])
                min = square_array[i][j];
        }
        min_in_row[i] = min;
    }
    cout << endl
         << "Min in rows: ";
    print_matrix(min_in_row, 1, 5);
    cout << endl
         << "Outputting array from right bottom up and down" << endl;

    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << square_array[j][i] << ' ';
        }
    }
    bool symmetric;
    int new_array1[5][5]; // обернути відносно головної діагоналі
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (square_array[i][j] != square_array[j][i])
                symmetric = false;
            new_array1[j][i] = square_array[i][j];
        }
    }
    cout << endl
         << "Reversed array: ";
    print_matrix(new_array1[0], 5, 5);
    int new_array2[5][5]; // rotate by 90 degrees
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            new_array2[j][4 - i] = square_array[i][j];
        }
    }
    cout << endl
         << "Rotated array: ";
    print_matrix(new_array2[0], 5, 5);
    cout << endl
         << "Array is symmetrical: " << symmetric;

    array<array<int, 6>, 5> other_array;
    for (int i = 0; i < 5; i++)
    {
        other_array[i].fill(i);
    }
    int new_array3[6][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            new_array3[j][i] = other_array[i][j];
        }
    }
    cout << endl
         << "5*6 array: ";
    print_matrix(other_array[0].data(), 5, 6);

    cout << endl
         << "Transposed array: ";
    print_matrix(new_array3[0], 6, 5);
    array<array<int, 5>, 6> other_array2;
    for (int i = 0; i < 6; i++)
    {
        other_array2[i].fill(i);
    }
    // Multiplying matrices
    int result[5][5], sum;
    for (int column = 0; column < 5; column++)
    {
        for (int i = 0; i < 5; i++)
        {
            sum = 0;
            for (int j = 0; j < 6; j++)
            {
                sum += other_array[i][j] * other_array2[j][column];
            }
            result[i][column] = sum;
        }
    }
    cout << endl
         << "A: ";
    print_matrix(other_array[0].data(), 5, 6);
    cout << endl
         << "B: ";
    print_matrix(other_array2[0].data(), 6, 5);
    cout << endl
         << "AB: ";
    print_matrix(result[0], 5, 5);
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int det = 0, submatrix[2][2], subcol;
    // Calculating determinant
    for (int i = 0; i < 3; i++)
    {
        for (int i1 = 1; i1 < 3; i1++)
        {
            subcol = 0;
            for (int j1 = 0; j1 < 3; j1++)
            {
                if (j1 == i)
                    continue;
                submatrix[i1 - 1][subcol++] = matrix[i1][j1];
            }
        }
        det += matrix[0][i] * pow(-1, i) * (submatrix[0][0] * submatrix[1][1] - submatrix[1][0] * submatrix[0][1]);
    }
    cout << endl
         << "A: ";
    print_matrix(matrix[0], 3, 3);
    cout << endl
         << "Determinant = " << det;

    //-----------------------------------------------------------------------
    // Find most frequent element
    int count, maxcount = 0, element;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            count = 0;
            for (int i0 = 0; i0 < 5; i0++)
            {
                for (int j0 = 0; j0 < 5; j0++)
                {
                    if (square_array[i][j] == square_array[i0][j0])
                        count++;
                }
            }
            if (count > maxcount)
            {
                maxcount = count;
                element = square_array[i][j];
            }
        }
    }
    cout << endl
         << "Most frequent element: " << element << " Repeats for " << maxcount << " times!";

    return 0;
}