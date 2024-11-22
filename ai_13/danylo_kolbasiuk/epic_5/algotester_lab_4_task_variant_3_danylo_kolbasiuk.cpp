#include <set>
#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    std::vector<int> one;
    std::vector<int> two;
    std::vector<int> three;
    std::vector<int> res;
    for (int i : arr)
    {
        if (i%3==0)
        {
            one.push_back(i);
        }
        else if (i%3==1)
        {
            two.push_back(i);
        }
        else if (i%3==2)
        {
            three.push_back(i);
        }
    }
    std::sort(one.begin(), one.end());
    std::sort(two.begin(), two.end(), std::greater<int>());
    std::sort(three.begin(), three.end());
    res.insert(res.end(), one.begin(), one.end());
    res.insert(res.end(), two.begin(), two.end());
    res.insert(res.end(), three.begin(), three.end());
    std::vector<int>::iterator it;
    it=std::unique(res.begin(), res.end());
    res.resize(std::distance(res.begin(), it));
    std::cout << res.size() << std::endl;
    for (int i : res)
    {
        std::cout << i << " "; 
    }
}
