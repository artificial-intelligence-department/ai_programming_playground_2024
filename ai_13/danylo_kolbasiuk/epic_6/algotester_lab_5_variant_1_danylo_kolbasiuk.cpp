#include <vector>
#include <iostream>
#include <cstdint>

int main()
{
    uint64_t A;
    int N;
    std::cin >> A >> N;
    std::vector<std::pair<int,int>> coords(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> coords[i].first >> coords[i].second;
        coords[i].first--;
        coords[i].second--;
    }
    for(const auto& [x,y] : coords)
    {
        for(int i=0; i<8; i++) 
        {
            A ^= uint64_t(1) << (x*8+i);
        }
        for(int i=0; i<8; i++) 
        {
            A ^= uint64_t(1) << (i*8+y);
        }
        A ^= uint64_t(1) << (x*8+y);
    }
    std::cout << A;
}