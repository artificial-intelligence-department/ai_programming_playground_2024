#include <iostream>
using namespace std;
struct Dynamic_array
{
    int size = 0;
    int capacity = 1;
    int growth_factor = 2;
    int *array = nullptr;
    Dynamic_array()
    {
        array = new int[capacity];
    }
    ~Dynamic_array()
    {
        delete[] array; // Deallocate the memory for the dynamic array
    }
    void reallocate(int new_capacity)
    {
        int *new_array = new int[new_capacity];

        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }

public:
    void insert(int index, int N, int *arr)
    {

        while (capacity <= size + N)
        {
            capacity *= growth_factor; // increase array capacity
            reallocate(capacity);
        }
        for (int i = size; i > index; i--)
        {
            array[i - 1 + N] = array[i - 1]; // move elements after index by N
        }
        int j = 0;
        for (int i = index; i < index + N; i++)
        {
            array[i] = arr[j++]; // add N elements from arr
        }
        size += N;
    }

    void erase(int index, int n)
    {
        size -= n;
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + n];
        }
    }
    int &operator[](int index)
    {
        return array[index];
    }
};
ostream &operator<<(ostream &os, Dynamic_array &a) // overload cout
{
    for (int i = 0; i < a.size; i++)
    {
        os << a.array[i] << ' ';
    }
    return os;
}
int main()
{
    Dynamic_array a;
    int N;
    cin >> N;
    string func;
    int index, size, value;
    for (int i = 0; i < N; i++)
    {                // N times
        cin >> func; // input type of request
        if (func == "insert")
        {
            cin >> index >> size;
            int *array_cin = new int[size];
            for (int i = 0; i < size; i++)
            {
                cin >> array_cin[i];
            }
            a.insert(index, size, array_cin);
            delete[] array_cin;
        }
        else if (func == "erase")
        {
            cin >> index >> size;
            a.erase(index, size);
        }

        else if (func == "size")
        {
            cout << a.size << endl;
        }
        else if (func == "capacity")
        {
            cout << a.capacity << endl;
        }
        else if (func == "get")
        {
            cin >> index;
            cout << a[index] << endl;
        }
        else if (func == "set")
        {
            cin >> index >> value;
            a[index] = value;
        }
        else // print
        {
            cout << a << endl;
        }
    }
    return 0;
}