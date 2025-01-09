#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        std::cin >> a[i];

    int max_t = 0;
    int counter = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (a[i] >= k) 
            counter++;
        else 
        {
            max_t = std::max(max_t, counter);
            counter = 0;
        }
    }

    
    max_t = std::max(max_t, counter);

    std::cout << max_t << std::endl;

    return 0;
}

