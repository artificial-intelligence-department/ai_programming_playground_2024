#include <iostream>
#include <string>

int const MAXLENGTH = 256;

void showFile(FILE* F){
    char buffer[MAXLENGTH];

    fseek(F, 0, SEEK_SET);

    while(fgets(buffer, MAXLENGTH, F)) std::cout << buffer;
    std::cout << std::endl;
}

int countSymbsInLastWord(FILE* F){
    int counter = 0;
    bool whitespace = false;
    char buffer[MAXLENGTH];

    fseek(F, 0, SEEK_SET);
    while(fgets(buffer, MAXLENGTH, F));
    for(int i = 0; buffer[i] != '\0'; i++){
        if(buffer[i] == ' ') whitespace = true;
        else if(whitespace && buffer[i] != ' ') {
            whitespace = false;
            counter = 1;
        }
        else counter++;
    }
    return --counter;
}

int main(){

    int const MAXLINES = 32;
    FILE* F1;
    FILE* F2;
    char F1NAME[] = "text1.txt";
    char F2NAME[] = "text2.txt";
    F1 = fopen(F1NAME, "r+");
    F2 = fopen(F2NAME, "w+");
    if(F1 == NULL) F1 = fopen(F1NAME, "w+");
    char line[MAXLENGTH];
    std::cout << "Enter lines for file1\n";
    std::cout << "Enter !! to exit\n";
    fseek(F1, 0, SEEK_END);
    while(true){
        std::cin.getline(line, MAXLENGTH);
        if(line[0] == '!' && line[1] == '!')break;
        fputs(line, F1);
        fputc('\n', F1); 
    }

    std::cout << "F1: \n";
    showFile(F1);

    int i = 1;
    fseek(F1, 0, SEEK_SET);
    while(fgets(line, MAXLENGTH, F1)){
        if(i > 3) {
            fputs(line, F2);
        }
        i++;
    }
    std::cout << "F2: \n";
    showFile(F2);
    
    std::cout << "Symbols in last word: " << countSymbsInLastWord(F2);

    fclose(F1);
    fclose(F2);
    delete F1;
    delete F2;
    //delete[] line;
    return 0;
}