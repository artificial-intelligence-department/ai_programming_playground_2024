#include <iostream>
#include <algorithm>

template<typename T>
void swap(T& a, T& b) 
{
    T temp = a;  
    a = b;       
    b = temp;    
}

template<typename T>
T* partition(T* first, T* last) 
{
    T* pivot = last - 1; 
    T* i = first - 1;

    for (T* j = first; j < last - 1; ++j) 
    {
        if (*j < *pivot) 
        {
            ++i;
            swap(*i, *j);
        }
    }

    swap(*(i + 1), *pivot);
    return i + 1; 
}

template<typename T>
void sort(T* first, T* last) 
{
    if (first >= last) return;

    T* pivot = partition(first, last);

    sort(first, pivot);
    sort(pivot + 1, last);
}

template<typename T>
void rotate(T* first, T* middle, T* last) 
{
    if (first == middle || middle == last) return; 

    T* left = first;
    T* right = middle - 1;
    while (left < right) 
    {
        std::swap(*left, *right);
        ++left;
        --right;
    }

    left = middle;
    right = last - 1;
    while (left < right) 
    {
        swap(*left, *right);
        ++left;
        --right;
    }

    left = first;
    right = last - 1;
    while (left < right) 
    {
        swap(*left, *right);
        ++left;
        --right;
    }
}

template<typename T>
T* unique(T* first, T* last)
{
    int n = last - first;
    int offset = 0;
    for (int i = 1; i < n; i++)
    {
        if (first[i] == first[i - 1])
        {
            offset++;
        }
        first[i - offset] = first[i];
    }
    n -= offset;
    return first + n;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sort(a, a+n);
    n = unique(a, a+n) - a;
    k %= n;
    rotate(a, a+k, a+n);
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
}