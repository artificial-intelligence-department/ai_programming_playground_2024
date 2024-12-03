// variant 68
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
int function_1();
std::vector<std::vector<int>> function_2(int &x);
int main()
{
    int x = function_1();
    std::cout << x << '\n';
    std::vector<std::vector<int>> tower = function_2(x);
}

int function_1()
{
    float a, b;
    std::cin >> a >> b;
    int c, d, e;
    std::cin >> c >> d >> e;
    double f;
    std::cin >> f;
    std::vector<double> vec = {(double)a, (double)b, (double)c, (double)d, (double)e, (double)f};
    std::vector<double> biggest(3);
    std::vector<double> smallest(3);
    std::vector<double> vec_temp = vec;
    for (int i = 0; i < 3; i++)
    {
        biggest[i] = *std::max_element(vec_temp.begin(), vec_temp.end());
        vec_temp.erase(find(vec_temp.begin(), vec_temp.end(), biggest[i]));
        smallest[i] = *std::min_element(vec_temp.begin(), vec_temp.end());
        vec_temp.erase(find(vec_temp.begin(), vec_temp.end(), smallest[i]));
    }
    double big_sum = std::accumulate(biggest.begin(), biggest.end(), 0);
    double smal_sum = std::accumulate(smallest.begin(), smallest.end(), 0);
    if (big_sum > smal_sum * 4)
    {
        return (big_sum + smal_sum) / 68;
    }
    else if (big_sum > smal_sum * 3)
    {
        return (big_sum * smal_sum) / 68;
    }
    else if (big_sum > smal_sum * 2)
    {
        return (big_sum * smal_sum) / 68;
    }
    return 0;
}

std::vector<std::vector<int>> function_2(int &x)
{
    std::vector<std::vector<int>> matrix(5, std::vector<int>{x, x, x, x, x});
    for (int i = 0; i < matrix.size(); i++) // рядок
    {
        for (int j = 0; j < matrix.size(); j++) // стовпець
        {
            matrix[i][j] = (matrix[i][j] + 68 + j + i) * (rand() % 100 + 1);
        }
    }
    for (auto el1 : matrix)
    {
        for (auto el2 : el1)
        {
            std::cout << el2 << " ";
        }
        std::cout << '\n';
    }
    return matrix;
}
