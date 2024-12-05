#include <iostream>
#include <string>
using namespace std;

struct dynamicArray
{
private:
    int *data;
    int size;
    int capacity;

    void resize(int newSize)
    {
        int *newData = new int[newSize];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newSize;
    }

public:
    dynamicArray()
    {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }
    ~dynamicArray()
    {
        delete[] data;
    }
    void insert(int index, int N, int *arr)
    {
        while (size + N >= capacity)
            capacity *= 2;
        resize(capacity);

        for (int i = size - 1; i >= index; i--)
        {
            data[i + N] = data[i];
        }
        for (int i = 0; i < N; i++)
        {
            data[index + i] = arr[i];
        }
        size = size + N;
        if (size == capacity)
        {
            capacity *= 2;
            resize(capacity);
        }
    }
    void erase(int index, int n)
    {
        for (int i = index; i < size - n; i++)
        {
            data[i] = data[i + n];
        }
        size = size - n;
    }
    int getSize()
    {
        return size;
    }
    int getCapacity()
    {
        return capacity;
    }
    int &operator[](int index)
    {
        return data[index];
    }
    friend ostream &operator<<(ostream &output, const dynamicArray &arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            output << arr.data[i] << ' ';
        }
        return output;
    }
};

int main()
{
    dynamicArray dynArr;
    int Q;
    cin >> Q;
    string str;

    for (int i = 0; i < Q; i++)
    {
        cin >> str;
        if (str == "insert")
        {
            int index;
            cin >> index;
            int N;
            cin >> N;
            int arr[N];
            for (int i = 0; i < N; i++)
            {
                cin >> arr[i];
            }
            dynArr.insert(index, N, arr);
        }
        else if (str == "erase")
        {
            int index;
            cin >> index;
            int n;
            cin >> n;
            dynArr.erase(index, n);
        }
        else if (str == "size")
        {
            cout << dynArr.getSize() << endl;
        }
        else if (str == "capacity")
        {
            cout << dynArr.getCapacity() << endl;
        }
        else if (str == "get")
        {
            int index;
            cin >> index;
            cout << dynArr[index] << endl;
        }
        else if (str == "set")
        {
            int index;
            cin >> index;
            int newElement;
            cin >> newElement;
            dynArr[index] = newElement;
        }
        else if (str == "print")
        {
            cout << dynArr << endl;
        }
    }

    return 0;
}
