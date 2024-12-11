#include<iostream>

void printArray(double* arr , const size_t& size, const char* name)
{
    std::cout << name << ' ';
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void checkerMatrix5x5(double** matrix)
{
    double maxColumnElement[5];
    for (size_t i = 0; i < 5; i++)
    {
        double max = matrix[0][i];
        for (size_t j = 0; j < 5; j++)
        {
            if(matrix[j][i] > max) max = matrix[j][i];
        }
        maxColumnElement[i] = max;
    }
    printArray(maxColumnElement, 5, "Max elements in columns:");

    double minColumnElement[5];
    for (size_t i = 0; i < 5; i++)
    {
        double min = matrix[0][i];
        for (size_t j = 0; j < 5; j++)
        {
            if(matrix[j][i] < min) min = matrix[j][i];
        }
        minColumnElement[i] = min;
    }
    printArray(minColumnElement, 5, "Min elements in columns:");

    double maxRowElements[5];
    for (size_t i = 0; i < 5; i++)
    {
        double max = matrix[i][0];
        for (size_t j = 0; j < 5; j++)
        {
            if(matrix[i][j] > max) max = matrix[i][j];
        }
        maxRowElements[i] = max;
    }
    printArray(maxRowElements, 5, "Max elements in rows:");

    double minRowElements[5];
    for (size_t i = 0; i < 5; i++)
    {
        double min = matrix[i][0];
        for (size_t j = 0; j < 5; j++)
        {
            if(matrix[i][j] < min) min = matrix[i][j];
        }
        minRowElements[i] = min;
    }
    printArray(minRowElements, 5, "Min elements in rows:");

    std::cout << "Matrix from bottom-right corner up and down: ";
    for (int j = 4; j >= 0; j--)
    {
        for (int i = 4; i >= 0; i--)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matrix from bottom-right corner left to right: " << std::endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matrix transposed along the main diagonal: " << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matrix rotated by 90 degrees clockwise: " << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        for (int j = 4; j >= 0; j--)
        {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    bool isSymmetric = true;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    std::cout << (isSymmetric ? "Matrix is symmetric" : "Matrix is not symmetric") << std::endl;
}

int main(void)
{
    double matrixValues[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    double* matrix[5];
    for (size_t i = 0; i < 5; i++)
    {
        matrix[i] = matrixValues[i];
    }

    checkerMatrix5x5(matrix);

    return 0;
}