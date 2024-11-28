#include <iostream>
#include <vector>

int main()
{
    int n, total;
    int sum=0;
    int temp;
    std::cin >> n >> total;
    std::vector<int> nummers(n-1);
    for(int i=0; i<n-1; i++)
    {
        std::cin >> temp;
        nummers.push_back(temp);
        sum+=temp;
    }
    if((total-sum)>0)
    {
        std::cout << total-sum << std::endl;
    }
    else
    {
        std::cout << "Another mistake!" << std::endl;    
    }
}
