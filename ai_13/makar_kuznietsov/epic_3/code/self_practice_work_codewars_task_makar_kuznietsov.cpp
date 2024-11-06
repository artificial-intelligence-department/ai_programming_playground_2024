#include <algorithm>
#include <iostream>

long long mygcd(long long a, long long b);

int main()
{
    long long a = 12312412;
    long long b = 12425251;
    std::cout << mygcd(a, b);
    return 0;
}

long long mygcd(long long a, long long b)
{
    long long min = std::min(a, b);
    long long max = std::max(a, b);
    if (max % min == 0)
    {
        return min;
    }
    else
    {
        return mygcd(max - min, min);
    }
}
