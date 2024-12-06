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
    if (command == "insert") return insert_arr;
    if (command == "erase") return erase_arr;
    if (command == "size") return size_arr;
    if (command == "capacity") return capacity_arr;
    if (command == "get") return get_arr;
    if (command == "set") return set_arr;
    if (command == "print") return print_arr;
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
        copy(data, data + size_, new_data);
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
        while (size_ + N > capacity_)
        {
            resize(capacity_ * 2);
        }

        for (int i = size_ - 1; i >= index; --i)
        {
            data[i + N] = data[i];
        }

        for (int i = 0; i < N; ++i)
        {
            data[index + i] = arr[i];
        }

        size_ += N;
    }

    void erase(int index, int n)
    {
        for (int i = index; i < size_ - n; ++i)
        {
            data[i] = data[i + n];
        }
        size_ -= n;
    }

    int size() const { return size_; }
    int capacity() const { return capacity_; }

    T &operator[](int index) { return data[index]; }

    friend ostream &operator<<(ostream &os, const dynamic_array &arr)
    {
        for (int i = 0; i < arr.size_; ++i)
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

    while (Q--)
    {
        string option;
        cin >> option;

        switch (get_operation(option))
        {
        case insert_arr:
        {
            int index, N;
            cin >> index >> N;
            int *arr = new int[N];
            for (int i = 0; i < N; ++i)
            {
                cin >> arr[i];
            }
            dynamic_arr.insert(index, N, arr);
            delete[] arr;
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
            cout << dynamic_arr.size() << endl;
            break;
        case capacity_arr:
            cout << dynamic_arr.capacity() << endl;
            break;
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
            cout << dynamic_arr << endl;
            break;
        default:
            cerr << "Invalid operation!" << endl;
        }
    }

    return 0;
}

