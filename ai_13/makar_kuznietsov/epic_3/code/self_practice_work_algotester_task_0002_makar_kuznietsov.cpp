#include <algorithm>
#include <iostream>
#include <vector>

int longIncSub(std::vector<int> &a, int &n);

int main()
{
    int n;
    std::vector<int> a;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        a.push_back(temp);
    }
    std::cout << longIncSub(a, n);
}

int longIncSub(std::vector<int> &a, int &n)
{
    std::vector<int> dummy(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int n = 0; n < i; n++)
        {
            if (a[i] > a[n] && dummy[i] < dummy[n] + 1)
            {
                dummy[i] = dummy[n] + 1;
            }
        }
    }
    return *std::max_element(dummy.begin(), dummy.end());
}
