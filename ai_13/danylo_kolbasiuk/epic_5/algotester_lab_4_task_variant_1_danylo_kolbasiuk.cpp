#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n, m;
    std::cin >> n;
    int temp;
    std::vector<int> one(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> one[i];
    }
    std::cin >> m;
    std::vector<int> two(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> two[i];
    }

    std::cout << std::endl;
    std::sort(one.begin(), one.end());
    std::sort(two.begin(), two.end());
    std::vector<int> result1;
    std::set_difference(one.begin(), one.end(), two.begin(), two.end(), inserter(result1, result1.end()));
    std::cout << result1.size() << std::endl;
    for (int i : result1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> result2;
    std::set_difference(two.begin(), two.end(), one.begin(), one.end(), inserter(result2, result2.end()));
    std::cout << result2.size() << std::endl;
    for (int i : result2)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> result3;
    std::set_intersection(one.begin(), one.end(), two.begin(), two.end(), inserter(result3, result3.end()));
    std::cout << result3.size() << std::endl;
    for (int i : result3)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> result4;
    std::set_union(one.begin(), one.end(), two.begin(), two.end(), inserter(result4, result4.end()));
    std::cout << result4.size() << std::endl;
    for (int i : result4)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> result5;
    std::set_symmetric_difference(one.begin(), one.end(), two.begin(), two.end(), inserter(result5, result5.end()));
    std::cout << result5.size() << std::endl;
    for (int i : result5)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}