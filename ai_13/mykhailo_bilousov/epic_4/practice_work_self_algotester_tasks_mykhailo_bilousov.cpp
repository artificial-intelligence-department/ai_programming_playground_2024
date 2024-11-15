// lab 2v1
#include <iostream>
#include <algorithm>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int n,a,b;
    std::cin >> n;
    int* r = new int[n];
    for(int i = 0; i < n; i++) std::cin >> r[i];
    auto minmax = std::minmax_element(r, r+n);
    int min = *minmax.first;
    int max = *minmax.second;

    *minmax.first = max;
    a = *std::max_element(r, r+n)-*std::min_element(r, r+n);
    *minmax.first = min;

    *minmax.second = min;
    b = *std::max_element(r, r+n)-*std::min_element(r, r+n);
    *minmax.second = max;

    std::cout << MIN(a,b);
}