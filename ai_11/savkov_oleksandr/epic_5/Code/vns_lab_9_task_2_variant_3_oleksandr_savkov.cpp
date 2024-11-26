#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

bool sameEl(const char* line) {
    int length = strlen(line);
    if (length == 0) return false;

    
    char first = tolower(line[0]);
    char last = tolower(line[length - 1] == '\n' ? line[length - 2] : line[length - 1]);
    return first == last;
}

int main() {
    const int MAXLINE = 255; 
    FILE *in, *out;
    char buf[MAXLINE];

    in = fopen("F1.txt", "w");
    if (in == NULL) {
        cerr << "Не вдалося відкрити файл F1.txt для запису." << endl;
        exit(1);
    }

    fputs("apple\n", in);
    fputs("banana\n", in);
    fputs("civic\n", in);
    fputs("radar\n", in);
    fputs("level\n", in);
    fputs("test\n", in);
    fputs("example\n", in);
    fputs("hello\n", in);
    fputs("world\n", in);
    fputs("anaconda\n", in);
    fclose(in);

    in = fopen("F1.txt", "r");
    out = fopen("F2.txt", "w");
    if (in == NULL || out == NULL) {
        cerr << "Не вдалося відкрити файл для читання або запису." << endl;
        exit(2);
    }

    int totalCharacters = 0;

    while (fgets(buf, MAXLINE, in) != NULL ) {
        if (sameEl(buf)) {
            fputs(buf, out);
            totalCharacters += strlen(buf) - (buf[strlen(buf) - 1] == '\n' ? 1 : 0); 
        }
        
    }
    

    fclose(in);
    fclose(out);

    cout << "Кількість символів у файлі F2: " << totalCharacters << endl;

    out = fopen("F2.txt", "r");
    if (out == NULL) {
        cerr << "Не вдалося відкрити файл F2.txt для читання." << endl;
        exit(3);
    }

    cout << "Вміст файлу F2.txt:" << endl;
    while (fgets(buf, MAXLINE, out) != NULL) {
        cout << buf;
    }

    fclose(out);

    return 0;
}
