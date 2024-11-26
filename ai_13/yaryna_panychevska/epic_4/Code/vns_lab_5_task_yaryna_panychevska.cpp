#include <iostream>
using namespace std;
double Calculate_Average(int row, int column, int matrix[][100])
{
    double sum = 0.0;
    for (int i = 0; i < row; i++)
    {
        sum += matrix[i][column];
    }
    return sum / row;
}

int Greater_Average(int row, int column, int matrix[][100], int average)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][column] > average)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    const int columns = 100;
    int row;
    int column;

    cout << "Enter number or rows: ";
    cin >> row;
    cout << "Enter number or columns: ";
    cin >> column;
    if (column > columns)
    {
        cout << "Number of columns you entered is greater than allowed.";
            return 1;
    }

    int matrix[100][100];
    cout << "Enter elements for matrix: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
        }
    }

    double prev_average = Calculate_Average(row, 0, matrix);
    cout << "Average of column 1: " << prev_average << endl;

    for (int col = 1; col < column; col++)
    {
        int count = Greater_Average(row, col, matrix, prev_average);
        cout << "Column " << col + 1 << " has :" << count << " elements, which are greater than the average of column " << col << endl;

        prev_average = Calculate_Average(row, col, matrix);
        cout << "Average of column " << col + 1 << " is : " << prev_average << endl;
    }

    return 0;
}