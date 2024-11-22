#include <iostream>
#include <cstring>

template<typename T>
class DynamicArray
{
    size_t __size;
    size_t __capacity;
    T* __array;
    void grow()
    {
        __capacity *= 2;
        T* new_array = new T[__capacity];
        memcpy(new_array, __array, __size * sizeof(T));
        delete[] __array;
        __array = new_array;
    }
public:
    DynamicArray()
    {
        __size = 0;
        __capacity = 1;
        __array = new T[__capacity];
    }
    DynamicArray(const T* init_array, size_t size)
    {
        __size = size;
        __capacity = 1;
        while (__capacity < __size) __capacity *= 2;
        __array = new T[__capacity];
        memcpy(__array, init_array, size * sizeof(T));
    }
    T& operator[](size_t index)
    {
        return __array[index];
    }
    const T& operator[](size_t index) const
    {
        return __array[index];
    }
    size_t size()
    {
        return __size;
    }
    size_t capacity()
    {
        return __capacity;
    }
    void insert(size_t index, size_t size, const T* elements)
    {
        while (__capacity < __size + size + 1) grow();
        memmove(__array + index + size, __array + index, (__size - index) * sizeof(T));
        memcpy(__array + index, elements, size * sizeof(T));
        __size += size;
    }
    void erase(size_t index, size_t size)
    {
        if (index + size < __size) 
            memmove(__array + index, __array + index + size, (__size - index - size) * sizeof(T));
        __size -= size;
    }
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr)
    {
        for(int i = 0; i < arr.__size; i++) os << arr.__array[i] << " ";
        return os;
    }
};

int main()
{
    DynamicArray<int> l;
    std::string input;
    int q, index, count, value;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        std::cin >> input;
        if (input == "insert")
        {
            std::cin >> index >> count;
            std::cin.ignore();
            int* arr = new int[count];
            for (int j = 0; j < count; j++) std::cin >> arr[j];
            l.insert(index, count, arr);
            delete[] arr;
        }
        else if (input == "erase")
        {
            std::cin >> index; 
            std::cin >> count; 
            l.erase(index, count);
        }
        else if (input == "get")
        {
            std::cin >> index;
            std::cout << l[index] << std::endl;
        }
        else if (input == "set")
        {
            std::cin >> index;
            std::cin >> value;
            l[index] = value;
        }
        else if (input == "print")
        {
            std::cout << l << std::endl;
        }
        else if (input == "size")
        {
            std::cout << l.size() << std::endl;
        }
        else if (input == "capacity")
        {
            std::cout << l.capacity() << std::endl;
        }
    }
}