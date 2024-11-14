#include <algorithm>
#include <iostream>
#include <vector>
int findCount(std::vector<std::vector<int>> vec);
int main()
{
    std::vector<std::vector<int>> vec = {{16, 23, 45}, {52, 12, 5}, {123, 15, 65}};
    std::cout << findCount(vec);
}

int findCount(std::vector<std::vector<int>> vec)
{
    std::vector<int> diag;
    for (int i = 0; i < vec.size(); i++)
    {
        diag.push_back(vec[i][i]);
    }
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (i != j && vec[i][j] > *std::min_element(diag.begin(), diag.end()))
            {
                count++;
            }
        }
    }
    return count;
}
