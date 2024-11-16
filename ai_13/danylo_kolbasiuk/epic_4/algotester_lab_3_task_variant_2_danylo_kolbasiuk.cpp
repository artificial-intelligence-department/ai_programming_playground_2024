#include <iostream>
#include <vector>

int main()
{
    int n,m;
    int unions=0;
    int inters=0;
    std::cin >> n;
    int* a=new int[n];
    for(int i=0; i<n; i++)
    {
        std::cin>>a[i];
    }
    std::cin >> m;
    int* b=new int[m];
    for(int i=0; i<m; i++)
    {
        std::cin>>b[i];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (a[i]==b[j])
            {
                inters++;
            }
        }
    }
    std::cout << inters << std::endl;
    std::cout << n+m-inters;
}
