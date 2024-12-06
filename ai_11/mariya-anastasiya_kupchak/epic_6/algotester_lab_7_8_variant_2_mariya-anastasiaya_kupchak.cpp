#include <iostream>

using namespace std;

template <class T>
class dynamicArray 
{
private:
    T *data;

public:
    int size;
    int capacity;



    dynamicArray() 
    {
        this->size = 0;
        this->capacity = 1;
        this->data = new T[1];
    }

    void insert(int index, int chys, T *elements) 
    {
        while (size + chys >= capacity)
        {
            capacity *= 2;
        }
        T *temp = new T[capacity];

        for (int i = 0; i < index; i++)
        {
            temp[i] = data[i];
        }

        for (int i = 0; i < chys; i++)
        {
            temp[index + i] = elements[i];
        }

        for (int i = index; i < size; i++)
        {
            temp[i + chys] = data[i];
        }
            
        this->size += chys;
        delete[] data;
        data = temp;
    }

    void erase(int index, int chys) 
    {
        T *temp = new T[capacity];
        int newSize = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (i < index || i >= index + chys)
            {
                temp[newSize] = data[i];
                newSize++;
            }
        }
        this->size -= chys;
        delete[] data;
        data = temp;
    }

    T get(int index) 
    {
        return this->data[index];
    }

    void set(int index, T value) 
    {
        this->data[index] = value;
    }

    void print(const string &separator) 
    {
        for (int i = 0; i < this->size; i++) 
        {
            cout << data[i];
            if (i < size - 1) cout << separator;
        }
        cout << endl;
    }
};

int main() 
{
    dynamicArray<int> array;

    int queryCount;
    cin >> queryCount;

    while (queryCount--) 
    {
        string command;
        cin >> command;
        if (command == "insert") 
        {
            int index, chys;
            cin >> index >> chys;
            int *elements = new int[chys];

            for (int i = 0; i < chys; i++) 
            {
                cin >> elements[i];
            }

            array.insert(index, chys, elements);
            delete[] elements;
        } 
        else if (command == "erase") 
        {
            int index, chys;
            cin >> index >> chys;
            array.erase(index, chys);
        } 
        else if (command == "size") 
        {
            cout << array.size << endl;
        } 
        else if (command == "capacity") 
        {
            cout << array.capacity << endl;
        } 
        else if (command == "get") 
        {
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        } 
        else if (command == "set") 
        {
            int index, chys;
            cin >> index >> chys;
            array.set(index, chys);
        } 
        else if (command == "print") 
        {
            array.print(" ");
        }
    }

    return 0;
    
}
