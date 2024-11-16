#include <iostream>
#include <algorithm>
using namespace std;

struct CircularArray
{
    int arr[100]; 
    int size;    

    // функція для встановлення елементів масиву
    void setArray(const int *elements, int n)
    {
        size = n;
        for (int i = 0; i < size; i++)
            arr[i] = elements[i];
    }

    void get(int k, bool forward)
    {
        for (int i = 0; i < size; i++)
        {
            int index = forward ? (k + i) % size : (size + k - i) % size ;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    void delete_max()
    {
        int max_el = *max_element(arr, arr + size); 
        int new_size = 0;

        for (int i = 0; i < size; i++)
            if (arr[i] != max_el)
                arr[new_size++] = arr[i];
        size = new_size; 
    }
};

int main()
{
    CircularArray circle;
    int elements[] = {1, 2, 5, 5, 3, 4, 5, 4};
    int n = sizeof(elements) / sizeof(elements[0]);

    circle.setArray(elements, n);

    int k = 2;
    circle.get(k, false); // вивевдення масиву від k-го елемента вліво

    circle.delete_max(); // видалення максимальних елементів

    circle.get(k, true); // виведення масиву від k-го елемента вправо

    return 0;
}
