#include <iostream>
#include <string.h>
using namespace std;

int count_a (const char* line){
    int count = 0;
    int len = strlen(line);
    for (int i=0; i<len; i++) { 
        if (line[i] == 'a') {
            ++count;
        }
    }
    return count;
}

int main(){
    int MAXLINE=255;
    char buf[MAXLINE];
    FILE *in, *out;

    const char* file_in = "F1.txt"; 
    const char* file_out = "F2.txt"; 

    in = fopen(file_in, "w");
    if(in==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    fputs("panda\n", in);
    fputs("apple\n", in);
    fputs("dragon\n", in);
    fputs("opera\n", in);
    fputs("tea\n", in);
    fputs("acapella\n", in);
    fputs("cat\n", in);
    fputs("formula\n", in);
    fputs("mantra\n", in);
    fputs("autumn\n", in);
    fclose(in);

    in = fopen(file_in, "r");

    if (in==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    cout << "Вміст файлу F1:" << endl;
    while (fgets(buf, MAXLINE, in)) {
        cout << buf; 
    }
    fclose(in);

    in = fopen(file_in, "r");
    out = fopen(file_out, "w");

    if (in==NULL || out==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    int max_a = 0, max_line, line_number_F1 = 0, line_number_F2 = 0, N1, N2;
    cout << "Введіть N1 та N2: ";
    cin >> N1 >> N2; 

    while(fgets(buf, MAXLINE, in)){
        line_number_F1++;
        if (buf[strlen(buf)-2] == 'a' && line_number_F1 >= N1 && line_number_F1 <= N2){
            line_number_F2++;
            fputs(buf, out);
            if(count_a(buf)>max_a){
                max_a = count_a(buf);
                max_line = line_number_F2;
            }
        }
    }

    fclose(in);
    fclose(out);
    
    out = fopen(file_out, "r");
    if(out==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    cout << "Вміст вихідного файлу: " << endl;
    while (fgets(buf, MAXLINE, out)) {
        cout << buf;
    }

    fclose(out);
    cout << "Найбільше букв 'a' містить рядок №" << max_line;
    return 0;
}

