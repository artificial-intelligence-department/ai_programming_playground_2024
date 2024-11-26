#include<iostream>
#include<algorithm>
#include<vector>

int main(void)
{
    int N;
    std::cin >> N;
    std::vector<int> cats(N);
    for (int i = 0, sz = cats.capacity(); i < sz; i++)
    {
        std::cin >> cats[i];
    }
    std::cout << *std::max_element(cats.begin(), cats.end()) - *std::min_element(cats.begin(), cats.end());
    return 0;
}