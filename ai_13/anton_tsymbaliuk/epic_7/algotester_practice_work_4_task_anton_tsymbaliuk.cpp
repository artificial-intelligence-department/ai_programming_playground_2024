#include <iostream>

int main()
{
    int l = 1;
    int r = 1000000000;
    int n = r / 2;
    char symb;
    
    while (true) {
        std::cout << n << std::endl << std::flush;
        std::cin >> symb;
        if (symb == '>') {
            r = n - 1;
            n -= ((r - l) / 2) == 0 ? 1 : ((r - l) / 2);
        }
        if (symb == '<') {
            l = n + 1;
            n += ((r - l) / 2) == 0 ? 1 : ((r - l) / 2);
        }
        if (symb == '=') return 0;
    }
}
