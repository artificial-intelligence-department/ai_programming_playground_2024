#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    uint64_t a, N;
    cin >> a >> N;
    while (N--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 8; i++)
            if (i+1 != x) {
                uint64_t k = 1ULL << (i * 8 + y - 1);
                a ^= k ;
            }
        uint64_t l = 255ULL << ((x-1) * 8);
        a ^= l;
    }
    cout << a;
    return 0;
}
