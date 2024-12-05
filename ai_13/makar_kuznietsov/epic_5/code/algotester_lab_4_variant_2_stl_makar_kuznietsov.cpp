#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, k;
    int temp;
    std::vector<int> vec;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    k = k % vec.size();
    std::rotate(vec.begin(), vec.begin() + k, vec.end());

    std::cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    return 0;
}
