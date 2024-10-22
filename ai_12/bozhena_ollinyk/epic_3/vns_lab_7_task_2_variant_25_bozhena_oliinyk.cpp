#include <iostream>
#include <cmath>

using namespace std;

int lengthOfArr;
int rowsOf2DArr;
int colsOf2DArr;
int *onearray;
int **doubleArray;
int *redactedArr;
int **redacted2DArr;
int **arrayOR;
int z = 0;
int r = 0;
void inputArr()
{

    cout << "Input length of array: ";
    cin >> lengthOfArr;

    onearray = new int[lengthOfArr];

    for (int i = 0; i < lengthOfArr; i++)
    {
        cout << "Input element №" << i << " of array: ";
        cin >> onearray[i];
    }

    cout << "Input how many rows has 2D array: ";
    cin >> rowsOf2DArr;
    cout << "Input how many columns has 2D array: ";
    cin >> colsOf2DArr;

    doubleArray = new int *[rowsOf2DArr];
    for (int i = 0; i < rowsOf2DArr; i++)
    {
        doubleArray[i] = new int[colsOf2DArr];
        for (int j = 0; j < colsOf2DArr; j++)
        {
            cout << "Input element " << i << " " << j << " of array: ";
            cin >> doubleArray[i][j];
        }
    }
}

void betweenZeros()
{
    redactedArr = new int[lengthOfArr - z];
    for (int i = 0; i < lengthOfArr - z; i++)
    {
        if ((onearray[i - 1] == 0) && (onearray[i + 1] == 0))
        {
            int bz = onearray[i];
            for (int j = 0; j < lengthOfArr - z; j++)
            {
                onearray[j] = onearray[j + 1];
            }
            onearray[lengthOfArr - z] = bz;
            z++;
        }
        redactedArr[i] = onearray[i];
    }
}

void oddRows()
{
    redacted2DArr = new int *[rowsOf2DArr - r];
    int newRow = 0;

    for (int i = 0; i < rowsOf2DArr; i++)
    {
        if (i % 2 == 1)
        {
            r++;
            continue;
        }

        redacted2DArr[newRow] = new int[colsOf2DArr];
        for (int j = 0; j < colsOf2DArr; j++)
        {
            redacted2DArr[newRow][j] = doubleArray[i][j];
        }
        newRow++;
    }
}

void redactingArray(int *oldArr, int *newArr, int length)
{
    for (int i = 0; i < length; i++)
    {
        newArr[i] = oldArr[i];
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printDoubleArray(int **doubleArr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << doubleArr[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main()
{

    inputArr();
    cout << "Original array: ";
    printArray(onearray, lengthOfArr);
    betweenZeros();
    cout << "Redacted array: ";
    printArray(redactedArr, lengthOfArr - z);

    cout << "Original 2D array: " << endl;
    printDoubleArray(doubleArray, rowsOf2DArr, colsOf2DArr);
    oddRows();
    cout << "Redacted 2D array: " << endl;
    printDoubleArray(redacted2DArr, rowsOf2DArr - r, colsOf2DArr);

    delete[] onearray;
    delete[] redactedArr;
    for (int i = 0; i < rowsOf2DArr - r; i++)
    {
        delete[] doubleArray[i];
        delete[] redacted2DArr[i];
    }
    delete[] doubleArray;
    delete[] redacted2DArr;

    return 0;
}