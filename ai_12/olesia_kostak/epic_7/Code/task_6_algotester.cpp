#include <iostream>
#include <vector>
#include <algorithm>

bool findElement(std::vector<int> b, int size, int target);


int main() 
{
    int N, M;
    
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) 
        std::cin >> a[i];

    std::cin >> M;
    std::vector<int> b(M);
    for (int i = 0; i < M; ++i) 
        std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int arr_intersection = 0, arr_union = N + M;
    for(int i = 0; i < N; i++)
    {
        if (findElement(b, M, a[i]))
        {
            arr_union--;
            arr_intersection++;
        }
    }
    std::cout << arr_intersection << std::endl << arr_union;


    return 0;
}

bool findElement(std::vector<int> b, int size, int target) 
{
    for (int i = 0; i < size; i++) 
        if (b[i] == target) 
            return true; 
    return false; 
}