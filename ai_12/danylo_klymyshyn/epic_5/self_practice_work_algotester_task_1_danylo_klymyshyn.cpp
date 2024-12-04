#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char x[11];
    scanf("%d", &n);
    scanf("%s", x);

    int count = 0;

    for (int i = 0; i < n; ++i) {
        char statement[11];
        scanf("%s", statement);
        if (strcmp(statement, x) == 0) {
            ++count;
        }
    }

    if (count == n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
