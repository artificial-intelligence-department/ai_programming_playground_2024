// 0002 Найбільша зростаюча підпослідовність https://algotester.com/en/ArchiveProblem/DisplayWithFile/40782
#include <iostream>

int lis(int arr[], size_t n)
{
    int max = 0;
    int* lis = new int[n];
 
    for (size_t i = 0; i < n; i++) lis[i] = 1;
 
    for (size_t i = 1; i < n; i++)
        for (size_t j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    for (size_t i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];
 
    delete[] lis;
 
    return max;
}

int main()
{
    size_t n;
    std::cin >> n;
    int* arr = new int[n];
    for(size_t i = 0; i < n; i++) 
    {
        std::cin >> arr[i];
    }
    std::cout << lis(arr, n);
    return 0;
}