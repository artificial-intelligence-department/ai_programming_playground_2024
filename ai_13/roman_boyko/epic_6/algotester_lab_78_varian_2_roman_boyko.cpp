#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
private:
    T *array;

public:
    int capacity;
    int size;
    DynamicArray();
    void AddElements(int index, const T *values, int num);
    void erase(int index, int amount);
    T get(int index);
    void set(int index, const T &value);
    void print();
};

template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->size = 0;
    this->capacity = 1;
    this->array = new T[1];
}

template <typename T>
void DynamicArray<T>::AddElements(int index, const T *values, int num)
{
    while (size + num >= capacity)
    {
        capacity *= 2;
    }
    T *arrTemp = new T[capacity];
    for (int i = 0; i < index; i++)
    {
        arrTemp[i] = array[i];
    }
    for (int i = 0; i < num; i++)
    {
        arrTemp[i + index] = values[i];
    }
    for (int i = index; i < size; i++)
    {
        arrTemp[i + num] = array[i];
    }
    this->size += num;
    delete[] array;
    array = arrTemp;
}

template <typename T>
void DynamicArray<T>::erase(int index, int amount)
{
    for (int i = index; i < size - amount; i++)
    {
        array[i] = array[i + amount];
    }

    size -= amount;
}

template <typename T>
T DynamicArray<T>::get(int index)
{
    return array[index];
}

template <typename T>
void DynamicArray<T>::set(int index, const T &value)
{
    array[index] = value;
}

template <typename T>
void DynamicArray<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    DynamicArray<int> arr;
    int Q;
    string ch;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> ch;
        if (ch == "insert")
        {
            int index, N;
            cin >> index >> N;
            int *array1 = new int[N];
            for (int i = 0; i < N; i++)
            {
                cin >> array1[i];
            }
            arr.AddElements(index, array1, N);
            delete[] array1;
        }
        else if (ch == "erase")
        {
            int index, N;
            cin >> index >> N;
            arr.erase(index, N);
        }
        else if (ch == "size")
        {
            cout << arr.size << endl;
        }
        else if (ch == "capacity")
        {
            cout << arr.capacity << endl;
        }
        else if (ch == "get")
        {
            int index;
            cin >> index;
            cout << arr.get(index) << endl;
        }
        else if (ch == "set")
        {
            int index, num;
            cin >> index >> num;
            arr.set(index, num);
        }
        else if (ch == "print")
        {
            arr.print();
        }
    }
}