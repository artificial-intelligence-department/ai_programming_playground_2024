#include <iostream>
#include <vector>
int main()
{
    int n, m;
    std::vector<int> nv;
    std::vector<int> mv;
    int temp;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        nv.push_back(temp);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> temp;
        mv.push_back(temp);
    }
    int same = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nv[i] == mv[j])
            {
                same++;
            }
        }
    }
    std::cout << same << '\n' << nv.size() + mv.size() - same;
}
