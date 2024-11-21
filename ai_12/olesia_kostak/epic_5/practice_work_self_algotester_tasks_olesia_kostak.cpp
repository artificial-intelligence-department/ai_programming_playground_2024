#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<int> arr(N);
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::vector<int> arr0 = {};
    std::vector<int> arr1 = {};
    std::vector<int> arr2 = {};

    for(int el: arr)
    {
        if(el % 3 == 0)
            arr0.push_back(el);
        else if(el % 3 == 1)
            arr1.push_back(el);
        else if(el % 3 == 2)
            arr2.push_back(el);
    }

    for(int i = 0; i < arr0.size(); i++)
    {
        if(arr0[i] couner)
    }

    return 0;
}