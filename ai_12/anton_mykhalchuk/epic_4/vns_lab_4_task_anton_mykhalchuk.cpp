#include <iostream>
#include <random>
using namespace std;

int main()
{
    int elementToDelete, indexOfElementToDelete = -1, k, size;
    int arr[100], newArr[100];

    cout << "Enter the size of array: ";
    cin >> size;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(1, 100);

    for (int i = 0; i < size; ++i)
    {
        arr[i] = distr(gen);
    }

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the value you want to delete: ";
    cin >> elementToDelete;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == elementToDelete)
            indexOfElementToDelete = i;
    }

    if (indexOfElementToDelete != -1)
    {
        for (int i = indexOfElementToDelete; i < size; ++i)
        {
            arr[i] = arr[i + 1];
        }
        --size;
    }

    else
    {
        cout << "No value to delete!" << endl;
    }

    cout << "How many elements shall the array be shifted to the right: ";
    cin >> k;
    int newIndex;
    for (int i = 0; i < size; ++i)
    {
        newIndex = (i + k) % size;
        if (newIndex < 0)
        {
            newIndex = size + newIndex;
        }
        newArr[newIndex] = arr[i];
    }

    for (int i = 0; i < size; ++i)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;

    return 0;
}