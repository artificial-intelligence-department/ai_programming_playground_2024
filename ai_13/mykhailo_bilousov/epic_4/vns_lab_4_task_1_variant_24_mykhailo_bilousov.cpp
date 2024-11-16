#include <iostream>
#include <algorithm>

#define N 100

int main()
{
    srand(time(0));
    size_t n = N;
    int* ring = new int[n];
    for (size_t i = 0; i < n; i++) ring[i] = rand() % 0x10000;
    size_t k;
    std::cout << "Enter K from 0 to " << n << ": ";
    std::cin >> k;
    for (size_t i = k, j = 0; j < n; i = (i < n - 1) ? i + 1 : 0, j++)
    {
        std::cout << i << ": " << ring[i] << "\n";
    }
    std::sort(ring, ring + n);
    size_t offset = 0;
    int* new_ring = new int[N];
    for (size_t i = 0, j = 0; j < n; i = (i < n - 1) ? i + 1 : 0, j++)
    {
        if (ring[i] % 2) new_ring[i - offset] = ring[i];
        else offset++;
    }
    n -= offset;
    delete[] ring;
    ring = new_ring;
    std::cout << "Enter K from 0 to " << n << ": ";
    std::cin >> k;
    for (size_t i = k, j = 0; j < n; i = (i < n - 1) ? i + 1 : 0, j++)
    {
        std::cout << i << ": " << ring[i] << "\n";
    }
}