#include <iostream>
#include <stdio.h>

int main()
{
    int n;
    int l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &l, &r);
        std::cout << l + r << " ";
    }
    return 0;
}
