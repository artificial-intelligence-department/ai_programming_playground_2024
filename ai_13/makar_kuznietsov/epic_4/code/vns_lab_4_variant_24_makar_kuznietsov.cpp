#include <iostream>
void printFunc(int arr[], int size, int k);
void sortArr(int arr[], int size);
void delEven(int arr[], int &size);
int main()
{
    int size = 5;
    int arr[size] = {1, 23, 42, 25, 2};
    int k = 4;
    printFunc(arr, size, k);
    sortArr(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    delEven(arr, size);
    printFunc(arr, size, k);
}

void printFunc(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[(k + i) % size] << " ";
    }
    std::cout << '\n';
}

void sortArr(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void delEven(int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
}
