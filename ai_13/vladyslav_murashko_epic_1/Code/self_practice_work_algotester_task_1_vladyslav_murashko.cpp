#include <iostream>

int main()
{
    short list[9]{1, 2, 5, 10, 20, 50, 100, 200, 500};
    int price;
    int answ = 0;
    std::cin >> price;
    for (short i = 8; i >= 0;i--)
    {
        while(price >= list[i])
        {
            price -= list[i];
            answ++;
        }
    }

    std::cout << answ;

    return 0;
}