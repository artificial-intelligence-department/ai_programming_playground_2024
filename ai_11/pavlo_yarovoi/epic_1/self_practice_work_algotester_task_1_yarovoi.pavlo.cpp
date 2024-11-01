#include <stdio.h>

int main() {
    int bonds[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n, count = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < 9; i++) {
        if (n == 0) break;
        count += n / bonds[i];
        n %= bonds[i];
    }
    
    printf("%d\n", count);
    
    return 0;
}

