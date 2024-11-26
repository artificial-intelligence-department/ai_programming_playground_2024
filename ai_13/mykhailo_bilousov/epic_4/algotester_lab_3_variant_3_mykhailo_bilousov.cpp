#include <iostream>
#include <string>

int main()
{
    std::string S, comp;
    std::cin >> S;
    int count = 1;
    size_t sz = S.size();
    if (sz <= 1)
    {
        std::cout << S;
        return 0;
    }
    for (size_t i = 1; i <= sz; i++)
    {
        if (S[i] == S[i-1])
        {
            count++;
        }
        else
        {
            comp += S[i-1] + ((count > 1) ? std::to_string(count) : "");
            count = 1;
        }
    }
    std::cout << comp;
}