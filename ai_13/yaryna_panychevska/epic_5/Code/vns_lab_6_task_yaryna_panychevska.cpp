#include <stdio.h>
#include <cstdio>
using namespace std;
int main() {
    char s[256];
    printf("Write sentence: ");
    gets(s);

    int count_word = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((i == 0 || s[i - 1] == ' ') && (s[i] == 'a' || s[i] == 'A'))
        {
            count_word++;
        }
    }
    printf("Quantity of words that starts with 'A' : %d", count_word);
    return 0;
}
