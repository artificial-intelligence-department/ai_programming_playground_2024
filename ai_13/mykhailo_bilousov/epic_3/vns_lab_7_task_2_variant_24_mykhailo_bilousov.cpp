#include <iostream>
#include <sstream>
#include <string>

void delete_even(std::string& str) 
{
    std::stringstream s(str), s_new;
    std::string word_even, word_odd;
    while (s >> word_even >> word_odd)
    {
        s_new << word_odd << " ";
    }
    str = s_new.str();
}

void delete_even(int*& arr, size_t& size) 
{
    int* new_arr = new int[size];
    size_t offset = 0;
    for (size_t i = 0; i < size; i++) 
    {
        if (arr[i] % 2 == 0)
        {
            offset++;
            continue;
        }
        new_arr[i - offset] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    size -= offset;
}

int main()
{
    size_t size = 11;
    int* a = new int[size]{0,1,1,3,4,5,6,7,8,9,10};
    for (size_t i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << size << std::endl;
    delete_even(a, size);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << size << std::endl;
    delete_even(a, size);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << size << std::endl;

    std::string str = "Zero One Two Three Four Odd Even Lorem ipsum dolor sit amet even";
    std::cout << str << std::endl;
    delete_even(str);
    std::cout << str << std::endl;
    delete_even(str);
    std::cout << str << std::endl;
}