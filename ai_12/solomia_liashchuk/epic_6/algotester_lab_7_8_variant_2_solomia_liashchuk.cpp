#include <iostream>
using namespace std;

template<typename S>
class DynamicArray
{
    private:
    S* data;
    int size;
    int capacity;

    void createSize(int newCapcity)
    {
        S* newData = new S[newCapcity];
        for(int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapcity;
    }

    public:
    DynamicArray() : size(0), capacity(1)
    {
        data = new S[capacity];
    }
    ~DynamicArray()
    {
        delete[] data;
    }

    void insert(int index, int n, S* values)
    {
        if(size + n > capacity)
        {
            int new_capacity = capacity;
            while(size + n >= new_capacity)
            {
                new_capacity *= 2;
            }
            createSize(new_capacity);
        }
        for(int i = size - 1; i >= index; i--)
        {
            data[i + n] = data[i];
        }
        for(int i = 0; i < n; i++)
        {
            data[index + i] = values[i];
        }
        size += n;
        if(size == capacity)
        {
            capacity *= 2;
            createSize(capacity);
        }
    }

    void erase(int index, int n)
    {
        for (int i = index + n; i < size; i++)
        {
            data[i - n] = data[i];
        }
        size -= n;

    }

    int get_size() const
    {
        return size;
    }
    int get_capacity() const
    {
        return capacity;
    }
    S& operator[](int index)
    {
        if(index < 0 || index >= size)
        {
            throw out_of_range("ERROR");
        }
        return data[index];
    }
    friend ostream& operator<<(ostream& os, const DynamicArray& arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            os << arr.data[i] << (i < arr.size - 1 ? " " : "");
        }
        return os;
    }    

};

int main()
{
    DynamicArray<int> arr;
    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++)
    {
        string c;
        cin >> c;

        if(c == "insert")
        {
            int index, n;
            cin >> index >> n;
            int* values = new int[n];
            for(int j = 0; j < n; j++)
            {
                cin >> values[j];
            }
            arr.insert(index, n, values);
            delete[] values;
        }
        else if(c == "erase")
        {
            int index, n;
            cin >> index >> n;
            arr.erase(index, n);

        }
        else if (c == "size")
        { 
            cout << arr.get_size() << endl;
        }
        
        else if (c == "capacity") 
        { 
            cout << arr.get_capacity() << endl;
        }
        
        else if(c == "get")
        {
            int index;
            cin >> index;
            cout << arr[index] << endl;

        }
        else if(c == "set")
        {
            int index, value;
            cin >> index >> value;
            arr[index] = value;

        }
        else if (c == "print") 
        { 
            cout << arr << endl;
        }
    }
    return 0;
}