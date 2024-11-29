#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum Operation
{
    insert_arr,
    erase_arr,
    size_arr,
    capacity_arr,
    get_arr,
    set_arr,
    print_arr,
    invalid
};

Operation get_operation(const string &command)
{
    if (command == "insert")
        return insert_arr;
    if (command == "erase")
        return erase_arr;
    if (command == "size")
        return size_arr;
    if (command == "capacity")
        return capacity_arr;
    if (command == "get")
        return get_arr;
    if (command == "set")
        return set_arr;
    if (command == "print")
        return print_arr;

    return invalid;
}

template <typename T = int> 
class dynamic_array
{
private:
    T *data;
    int size_;
    int capacity_;

    void resize(int new_capacity)
    {
        T *new_data = new T[new_capacity];
        for (int i = 0; i < size_; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    dynamic_array() : size_(0), capacity_(1)
    {
        data = new T[capacity_];
    }

    ~dynamic_array()
    {
        delete[] data;
    }

    void insert(int index, int N, T *arr)
    {
        if (size_ + N > capacity_)
        {
            while (capacity_ <= size_ + N)
            {
                capacity_ *= 2;
            }
            resize(capacity_);
        }
        
        for (int i = size_ - 1; i >= index; i--)
        {
            data[i + N] = data[i];
        }

        for (int i = 0; i < N; i++)
        {
            data[index + i] = arr[i];
        }

        size_ += N;
        if (size_ == capacity_)
        {
            capacity_ *= 2;
            resize(capacity_);
        }
    }

    void erase(int index, int n)
    {
        for (int i = index; i < size_ - n; i++)
        {
            data[i] = data[i + n];
        }
        size_ -= n;
    }

    int size()
    {
        return size_;
    }

    int capacity()
    {
        return capacity_;
    }

    T &operator[](int index) { return data[index]; }

    friend ostream &operator<<(ostream &os, const dynamic_array &arr)
    {
        for (int i = 0; i < arr.size_; i++)
        {
            os << arr.data[i] << ' ';
        }
        return os;
    }
};

int main()
{
    int Q;
    cin >> Q;
    
    dynamic_array<int> dynamic_arr;

    for (int i = 0; i < Q; i++)
    {
        string option;
        cin >> option;
        Operation operation = get_operation(option);

        switch (operation)
        {
        case insert_arr:
        {
            int index, N;
            cin >> index >> N;
            int arr[N];
            for (int i = 0; i < N; i++)
            {
                cin >> arr[i];
            }
            dynamic_arr.insert(index, N, arr);
            break;
        }
        case erase_arr:
        {
            int index, n;
            cin >> index >> n;
            dynamic_arr.erase(index, n);
            break;
        }
        case size_arr:
        {
            cout << dynamic_arr.size() << endl;
            break;
        }
        case capacity_arr:
        {
            cout << dynamic_arr.capacity() << endl;
            break;
        }
        case get_arr:
        {
            int index;
            cin >> index;
            cout << dynamic_arr[index] << endl;
            break;
        }
        case set_arr:
        {
            int index, value;
            cin >> index >> value;
            dynamic_arr[index] = value;
            break;
        }
        case print_arr:
        {
            cout << dynamic_arr << endl;
            break;
        }
        default:
            break;
        }
    }
}