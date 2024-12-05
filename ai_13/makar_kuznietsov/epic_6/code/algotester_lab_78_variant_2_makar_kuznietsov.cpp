#include <cstddef>
#include <iostream>

template <typename T> class DynamicArray
{
  private:
    T *data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity)
    {
        T *new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

  public:
    DynamicArray() : data(new T[1]), size(0), capacity(1)
    {
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    size_t getSize() const
    {
        return size;
    }

    size_t getCapacity() const
    {
        return capacity;
    }

    void insert(size_t index, const T *elements, size_t count)
    {
        size_t new_size = size + count;
        if (new_size >= capacity)
        {
            size_t new_capacity = capacity * 2;
            while (new_capacity <= new_size)
            {
                new_capacity *= 2;
            }
            resize(new_capacity);
        }

        for (size_t i = size; i > index; --i)
        {
            data[i + count - 1] = data[i - 1];
        }

        for (size_t i = 0; i < count; ++i)
        {
            data[index + i] = elements[i];
        }

        size = new_size;
    }

    void erase(size_t index, size_t count)
    {
        for (size_t i = index; i + count < size; ++i)
        {
            data[i] = data[i + count];
        }
        size -= count;
    }

    T operator[](size_t index) const
    {
        return data[index];
    }

    T &operator[](size_t index)
    {
        return data[index];
    }

    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &arr)
    {
        for (size_t i = 0; i < arr.size; ++i)
        {
            os << arr.data[i] << " ";
        }
        return os;
    }
};

int main()
{
    DynamicArray<int> array;
    int Q;
    std::cin >> Q;

    while (Q--)
    {
        std::string command;
        std::cin >> command;

        if (command == "insert")
        {
            size_t index, N;
            std::cin >> index >> N;
            int *elements = new int[N];
            for (size_t i = 0; i < N; ++i)
            {
                std::cin >> elements[i];
            }
            array.insert(index, elements, N);
            delete[] elements;
        }
        else if (command == "erase")
        {
            size_t index, count;
            std::cin >> index >> count;
            array.erase(index, count);
        }
        else if (command == "size")
        {
            std::cout << array.getSize() << std::endl;
        }
        else if (command == "capacity")
        {
            std::cout << array.getCapacity() << std::endl;
        }
        else if (command == "get")
        {
            size_t index;
            std::cin >> index;
            std::cout << array[index] << std::endl;
        }
        else if (command == "set")
        {
            size_t index;
            int value;
            std::cin >> index >> value;
            array[index] = value;
        }
        else if (command == "print")
        {
            std::cout << array << std::endl;
        }
    }

    return 0;
}
