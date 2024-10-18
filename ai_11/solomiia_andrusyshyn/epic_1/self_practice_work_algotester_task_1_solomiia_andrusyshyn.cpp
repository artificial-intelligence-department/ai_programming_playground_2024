#include <stdio.h>

int main()
{
    int N, C = 0;
    scanf("%d", &N);
    int V[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    for(int i = 0; i < 9; ++i)
    {
        while(N >= V[i])
        {
            N -= V[i];
            C += 1;
        }
    }
    printf("%d", C);
    return 0;
}