#include <iostream>

using namespace std;

const int r = 4;
const int c = 4;

void matrix_print(int matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void saddle_point(int matrix[r][c])
{
    for (int i = 0; i < r; ++i)
    {
        int min_r = matrix[i][0];
        int c_index = 0;

        for (int j = 1; j < c; ++j)
        {
            if (matrix[i][j] < min_r)
            {
                min_r = matrix[i][j];
                c_index = j;
            }
        }

    
        bool is_saddle_point = true;
        for (int k = 0; k < r; ++k)
        {
            if (matrix[k][c_index] > min_r)
            {
                is_saddle_point = false;
                break;
            }
        }

        if (is_saddle_point)
        {
            cout << "Saddle point at (" << i << ", " << c_index << "), value: " << min_r << endl;
        }
    }

    for (int j = 0; j < c; ++j)
    {
        int min_c = matrix[0][j];
        int r_index = 0;

        for (int i = 1; i < r; ++i)
        {
            if (matrix[i][j] < min_c)
            {
                min_c = matrix[i][j];
                r_index = i;
            }
        }

        bool isSaddlePoint = true;
        for (int k = 0; k < c; ++k)
        {
            if (matrix[r_index][k] > min_c)
            {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint)
        {
            cout << "Saddle point at (" << j << ", " << r_index << "), value: " << min_c << endl;
        }
    }
}

int main()
{
    int matrix[r][c] = {{6, 7, 8, 9}, {1, 2, 3, 4}, {5, 6, 7, 8}, {1, 0, 11, 12}};
    cout << "Matrix:" << endl;
    matrix_print(matrix);
    saddle_point(matrix);
    return 0;
}