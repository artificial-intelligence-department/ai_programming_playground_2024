#include <iostream>
#include <cmath>

unsigned int kvadr(int variables_count, ...)
{
    int *ptr = &variables_count;
    unsigned int count = 0;
    while (variables_count != 0)
    {
        ptr+=2;
        if (round(sqrt(*ptr)) == sqrt(*ptr))
        {
            std::cout << sqrt(*ptr) << std::endl;
            count++;
        }
        variables_count--;
    }
    return count;
}

int main()
{
    double count1 = kvadr(3 ,1,4,9);
    double count2 = kvadr(7 ,1,4,9,3,5,7,10);
    double count3 = kvadr(11 ,1,4,9,13,22,25,11,53,64,81,90);

    std::cout << "Full squares count 1: " << count1 << std::endl;
    std::cout << "Full squares count 2: " << count2 << std::endl;
    std::cout << "Full squares count 3: " << count3 << std::endl;
    return 0;
}
