#include <iostream>
using namespace std;

int main()
{
    const int size = 10;

    int k;

    cout << "Введіть значення для k(від 0 до 9): ";
    cin >> k;

    int arr[size] = {1, 42, 11, 9, 37, 7, 23, 12, 4, 3};

    cout << "Цикл вліво: ";
    for (int i = 0; i < size; i++) 
    {
        int index = (k - i + size) % size; 
        cout << arr[index] << " ";
    }
    cout << endl;

    int newSize = size + 4;
    int newArr[newSize];

    newArr[0] = arr[0];
    for(int i = 0; i < newSize; i++)
    {
        newArr[i + 1] = arr[i];
    }

    newArr[size + 1] = arr[size - 3];  
    newArr[size + 2] = arr[size - 2];  
    newArr[size + 3] = arr[size - 1];

    int n;
    cout << "Введіть значення для k(від 0 до " << newSize - 1 << "): ";
    cin >> n;

    cout << "Цикл вправо: ";
    for (int i = 0; i < newSize; i++) 
    {
        int index = (n + i) % newSize; 
        cout << newArr[index] << " ";
    }
    cout << endl;

    return 0;
}