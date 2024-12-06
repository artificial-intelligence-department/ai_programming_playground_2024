#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


using namespace std;

int main () {
    const int LINEBUFFER = 512;
    char line[LINEBUFFER];
    int count = 0;

    FILE *f1;
    f1 = fopen("F1.txt", "wt+");
    if (f1 == NULL) {
        cerr << "Error openning file";
        return 0;
    }

    FILE *f2;
    f2 = fopen("F2.txt", "wt+" );
    if (f2 == NULL) {
        cerr << "Error openning file";
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        char lineInp[LINEBUFFER];
        fgets(lineInp, LINEBUFFER, stdin);
        fputs(lineInp, f1);
    }

    fclose(f1);

    f1 = fopen("F1.txt", "rt");
    if (f1 == NULL) {
        cerr << "Error openning file";
        return 0;
    }

    while (fgets(line, LINEBUFFER, f1) != NULL) {
        if (line[0] == '\n' || line[0] == '\0') {
            continue;
        }

        if (line[0] == 'a' || line[0] == 'A') {
            fputs(line, f2);
        }
    }

    fclose(f2);

    f2 = fopen("F2.txt", "rt");
    if (f2 == NULL) {
        cerr << "Error openning file";
        return 0;
    }

    while (fgets(line, LINEBUFFER, f2) != NULL) {
        char temp[LINEBUFFER];
        strcpy(temp, line);

        char* token = strtok(temp, " .");
        
        while (token != NULL) {
            count++;
            token = strtok(NULL, " .");
        }  
    }
    
    cout << endl;

    fseek(f2, 0, SEEK_SET);
    while (fgets(line, LINEBUFFER, f2) != NULL) {
        cout << line;
    }

    cout << endl;

    cout << count;

    fclose(f1);
    fclose(f2);
    
    return 0;
}
