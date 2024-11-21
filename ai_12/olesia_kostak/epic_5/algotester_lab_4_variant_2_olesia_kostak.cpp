#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
std::vector<int> mergeSort(const std::vector<int>& vec);


int main()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> set(N);

    for(int i = 0; i < N; i++)
        std::cin >> set[i];
    
    for(int i = 0; i < N; i++)
    {
        if(std::count(set.begin(), set.end(), set[i]) != 1)
        {
            set.erase(find(set.begin(), set.end(), set[i]));
            N--;
            i--;
        }
    }
    set = mergeSort(set);

    for(int i = 0; i < K; i++)
    {
        int index = 0;
        int temp = set[index];
        set.push_back(temp);
        set.erase(find(set.begin(), set.end(), temp));
    }
    
    std::cout << set.size() << std::endl;
    for(int i = 0; i < N; i++)
        std::cout << set[i] << " ";


    return 0;
}


std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) 
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) 
    {
        if (left[i] < right[j]) 
        {
            result.push_back(left[i]);
            i++;
        } else 
        {

            result.push_back(right[j]);
            j++;
        }
    }
    
    while (i < left.size()) 
    {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) 
    {
        result.push_back(right[j]);
        j++;
    }
    
    return result;
}

std::vector<int> mergeSort(const std::vector<int>& vec) 
{
    if (vec.size() <= 1) return vec;
    
    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());
    
    return merge(mergeSort(left), mergeSort(right));
}
