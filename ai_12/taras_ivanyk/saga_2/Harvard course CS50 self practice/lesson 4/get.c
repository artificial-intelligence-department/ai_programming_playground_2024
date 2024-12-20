#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);                   // & because, if we write n, we'll work only with
    // copy of n, not the original one, so we use & to go to address of n and change the
    // value of it

    printf("Your number is: %i\n", n);

    char *s;
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}