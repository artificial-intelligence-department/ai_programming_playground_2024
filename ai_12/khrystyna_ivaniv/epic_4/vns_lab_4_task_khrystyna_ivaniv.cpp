#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

void array_print(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    int array[N];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    srand(time(0));

    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }

    cout << "Array: ";
    array_print(array, size);

    int element_remove;
    cout << "Enter the element of the array you want to remove: ";
    cin >> element_remove;

    if (element_remove >= 0 && element_remove < size)
    {
        for (int i = element_remove; i < size - 1; ++i)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
    else
    {
        cout << "Invalid index(" << endl;
    }

    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
        {
            for (int j = size; j > i + 1; --j)
            {
                array[j] = array[j - 1];
            }
            array[i + 1] = array[i] + 2;
            size++;

            break;
        }
    }
    cout << "New array: " << endl;
    array_print(array, size);

    return 0;
}