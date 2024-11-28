#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


void inputInFile(const char* fileName1){
    FILE* fileStream;
    fileStream = fopen(fileName1, "w");
    if(fileStream == nullptr){
        cerr << "Не вдається відкрити файл";
        exit(0);
    }
    string temp;
    for(int i = 0; i < 5; i++){
        getline(cin, temp);
        fputs(temp.c_str(), fileStream);
        fputs("\n", fileStream);
    }
    fclose(fileStream);
}

void copy(const char* fileName1, const char* fileName2){
    FILE* fileStream1;
    FILE* fileStream2;
    fileStream1 = fopen(fileName1, "r");
    fileStream2 = fopen(fileName2, "w");
    if(fileStream1 == nullptr){
        cerr << "Не вдається відкрити файл1";
        exit(0);
    }
    if(fileStream2 == nullptr){
        cerr << "Не вдається відкрити файл2";
        fclose(fileStream1);
        exit(0);
    }
    cout << "Введіть N1 та N2: ";
    int N1, N2;
    cin >> N1 >> N2;
    if (N1 > N2) {
        cout << "Невірно задані номери рядків. N1 має бути меншим за N2" << endl;
        fclose(fileStream1);
        fclose(fileStream2);
        exit(0);
    }
    const int size = 50;
    char str[size];
    int current_line = 1;
    while(fgets(str, size, fileStream1)){
        if((str[0] == 'A' || str[0] == 'a') && current_line >= N1 && current_line <= N2){
            fputs(str, fileStream2);
        }
    }
    fclose(fileStream1);
    fclose(fileStream2);
}

bool isConsonant (char c){
    c = tolower(c);
    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int maxConsonant(const char* fileName){
    FILE* fileStream;
    fileStream = fopen(fileName, "r");
    if(fileStream == nullptr){
        cerr << "Не вдається відкрити файл";
        exit(0);
    }
    int maxConsonants = 0;  
    int lineNumber = 0;  
    int currentLine = 1;
    int consonantCount = 0;
    char str[50];
    while(fgets(str, 50, fileStream)){
        consonantCount = 0;
        currentLine++;
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            if(isConsonant(str[i])){
                consonantCount++;
            }
        }
        if (consonantCount > maxConsonants){
            maxConsonants = consonantCount;
            lineNumber = currentLine;
        }
        
    }
    return lineNumber;
}

int main() {
    const char* fileName1 = "F1.txt";
    const char* fileName2 = "F2.txt";
    inputInFile(fileName1);
    copy(fileName1, fileName2);
    cout << "Номер рядка з найбільшою кількістю приголосних - " << maxConsonant(fileName2);
    return 0;
}