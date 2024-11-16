#include <iostream>
using namespace std;

int countOccurrences(int arr[5][3], int rows, int cols, int num)
{
    int count = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if(arr[i][j] == num)
            {
                count++;
            }
        }
    }
    return count;            
}

int FindMax(int arr[5][3], int rows, int cols)
{
    int maxRepeated = -1; 
    bool foundMax = false; 

     for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            int currentElement = arr[i][j];

             if (countOccurrences(arr, rows, cols, currentElement) > 1) 
            {
                if (!foundMax || currentElement > maxRepeated) 
                {
                    maxRepeated = currentElement; 
                    foundMax = true;
                }
            }
        }
    }

    if(!foundMax)
    {
        return -1;
    }
    return maxRepeated;             
}

int main()
{
    int rows = 5;
    int cols = 3;

    int arr[5][3] =
    {
        {1, 2, 7},
        {5, 11, 6},
        {8, 27, 12},
        {9, 45, 6},
        {33, 27, 8}
    };

    int result = FindMax(arr, rows, cols);

    if (result != -1) 
    {
        cout << "Максимальний повторюваний елемент: " << result << endl;
    } 
    else 
    {
        cout << "Повторюваних елементів не знайдено." << endl;
    }

    return 0;
    
}