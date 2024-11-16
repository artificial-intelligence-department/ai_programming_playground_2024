#include <iostream>

using namespace std;

template <class T>
class SDA
{
private:
    T *arr;

public:
    int size;
    int capacity;

    SDA()
    {
        this->size = 0;
        this->capacity = 1;
        this->arr = new T[1];
    }

    void insert(int index, int amount, T *toInsert)
    {
        while (size + amount >= capacity)
            capacity *= 2;
        T *temp = new T[capacity];

        for (int i = 0; i < index; i++)
            temp[i] = arr[i];
        for (int i = 0; i < amount; i++)
            temp[index + i] = toInsert[i];
        for (int i = index; i < size; i++)
            temp[i + amount] = arr[i];
            
        this->size += amount;
        delete[] arr;
        arr = temp;
    }

    void erase(int index, int amount)
    {
        T *temp = new T[capacity];
        int acc = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (i < index || i >= index + amount)
            {
                temp[acc] = arr[i];
                acc++;
            }
        }
            this->size -= amount;
            delete[] arr;
            arr = temp;
    }

    T get(int index)
    {
        return this->arr[index];
    }

    void set(int index, T value)
    {
        this->arr[index] = value;
    }

    void operator<<(string separator)
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << separator;
        }
        cout << endl;
    }
};

int main()
{
    SDA<int> arr;

    int q;
    cin >> q;
    while (q--)
    {
        string line;
        cin >> line;
        if (line == "insert")
        {
            int index, N;
            cin >> index >> N;
            cin.ignore();
            int *temp = new int[N];

            for (int i = 0; i < N; i++)
            {
                int n;
                cin >> n;
                temp[i] = n;
            }

            arr.insert(index, N, temp);
            delete[] temp;
        }
        else if (line == "erase")
        {
            int index, N;
            cin >> index >> N;
            arr.erase(index, N);
        }
        else if (line == "size")
        {
            cout << arr.size << endl;
        }
        else if (line == "capacity")
        {
            cout << arr.capacity << endl;
        }
        else if (line == "get")
        {
            int i;
            cin >> i;
            cout << arr.get(i) << endl;
        }
        else if (line == "set")
        {
            int i, value;
            cin >> i >> value;
            arr.set(i, value);
        }
        else if (line == "print")
        {
            arr << " ";
        }
    }
    return 0;
}