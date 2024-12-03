#include <iostream>

template<typename T>
void swapElements(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T* partitionArray(T* begin, T* end) 
{
    T* pivot = end - 1;
    T* i = begin - 1;

    for (T* j = begin; j < end - 1; ++j) 
    {
        if (*j < *pivot) 
        {
            ++i;
            swapElements(*i, *j);
        }
    }

    swapElements(*(i + 1), *pivot);
    return i + 1;
}

template<typename T>
void quickSort(T* begin, T* end) 
{
    if (begin >= end) return;

    T* pivot = partitionArray(begin, end);

    quickSort(begin, pivot);
    quickSort(pivot + 1, end);
}

template<typename T>
void rotateArray(T* begin, T* mid, T* end) 
{
    if (begin == mid || mid == end) return;

    T* left = begin;
    T* right = mid - 1;
    while (left < right) 
    {
        swapElements(*left, *right);
        ++left;
        --right;
    }

    left = mid;
    right = end - 1;
    while (left < right) 
    {
        swapElements(*left, *right);
        ++left;
        --right;
    }

    left = begin;
    right = end - 1;
    while (left < right) 
    {
        swapElements(*left, *right);
        ++left;
        --right;
    }
}

template<typename T>
T* removeDuplicates(T* begin, T* end)
{
    int size = end - begin;
    int offset = 0;
    for (int i = 1; i < size; i++)
    {
        if (begin[i] == begin[i - 1])
        {
            offset++;
        }
        begin[i - offset] = begin[i];
    }
    size -= offset;
    return begin + size;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    quickSort(array, array + n);
    n = removeDuplicates(array, array + n) - array;
    k %= n;
    rotateArray(array, array + k, array + n);

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }

    delete[] array;
}
