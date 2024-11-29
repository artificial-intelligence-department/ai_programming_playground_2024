#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const char* filename1 = "file1.txt";
    const char* filename2 = "file2.txt";
    char content[256];

   
    cout << "Введіть вміст для запису у файл: ";
    cin.getline(content, sizeof(content));
    


    FILE* f1 = fopen(filename1, "w");
    
    if (f1 == nullptr) {
        cout << "Failure. File could not be created." << endl;
        exit(0);
    }

    int len = strlen(content);
    fwrite(content, sizeof(char), len, f1);
    if (0 == len) {
        fclose(f1);
        cout << "Failure. File could not be created." << endl;
        exit(0);
    }

    if (fclose(f1) != 0) {
        cout << "Failure. File could not be created." << endl;
        exit(0);
    }
    
    cout << "Success. File created." << endl;

    // F1 в F2

    FILE* f_from = fopen(filename1, "r");
    FILE* f_to = fopen(filename2, "w");

    if (f_from == nullptr || f_to == nullptr) {
        cout << "Failure coping file." << endl;
        exit(0);
    }

    char buffer[512];
    while (fgets(buffer, sizeof(buffer), f_from) != nullptr) {
        if (fputs(buffer, f_to) == EOF) {
            fclose(f_from);
            fclose(f_to);
            cout << "Failure coping file." << endl;
            exit(0);
        }
    }

    if (fclose(f_from) != 0 || fclose(f_to) != 0) {
        cout << "Failure coping file." << endl;
        exit(0);
    }

    cout << "Success. File is copied." << endl;

    return 0;
}
