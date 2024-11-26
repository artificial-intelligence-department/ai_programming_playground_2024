#include <stdio.h>
#include <string.h> 

int main() {
    char txt[255];

    fgets(txt, 255, stdin); // gets(txt)

    txt[strcspn(txt, "\n")] = '\0'; // для випадку з gets(txt) не потрібне

    int stop = strlen(txt);
    int size = strlen(txt);
    
    for (int i = 0; i != stop; i++) {
        if (txt[i] >= '0' && txt[i] <= '9') {
            int value = txt[i];
            for (int j = i; j < size; j++) {
                txt[j] = txt[j + 1];
            }
            txt[size - 1] = value;
            stop--;
            --i;
        }
    }

    for (int i = 0; i < size; i++) printf ("%c ", txt[i]);

    return 0;
}

