#include <iostream>
#include <unordered_map>
#include <vector>

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    int n, k;
    int temp;
    std::vector<int> vec;
    std::cin >> n >> k;
    std::unordered_map<int, int> nums;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if (nums[temp] == 0)
        {
            vec.push_back(temp);
        }
        nums[temp]++;
    }

    bubbleSort(vec);

    for (int i = 0; i < k; i++)
    {
        vec.push_back(vec[0]);
        vec.erase(vec.begin());
    }
    std::cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    return 0;
}
