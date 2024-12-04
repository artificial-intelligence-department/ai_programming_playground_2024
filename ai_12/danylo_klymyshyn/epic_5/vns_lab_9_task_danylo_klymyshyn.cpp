    #include <iostream>
    #include <cstring>

    void fileFill(){
    FILE *F1 = fopen("F1.txt", "w");
    if(!F1){
        std::cerr << "Error openning file. ";
        return ;
    }

    char temp[100]; 
    for(int i = 0; i < 4; ++i){
        std::cout << "Enter " << i+1 << " line: ";
        std::cin.getline(temp, sizeof(temp));
        if (fputs(temp, F1) == EOF || fputc('\n', F1) == EOF) { 
            std::cerr << "Error saving data.\n";
            fclose(F1);
            return;
    }
    }

    fclose(F1);
    }



void copy(){
    FILE *F1 = fopen("F1.txt", "r");
    FILE *F2 = fopen("F2.txt", "w");
    if(!F1 || !F2){
        std::cerr << "Error openning files.";
        return ;
    }

    char temp[100];
    const char delim[] = " .,!?";
    for(int i = 0; i < 4; ++i){
        fgets(temp, sizeof(temp), F1);
        char *token = strtok(temp, delim);
        if(token != nullptr && strtok(nullptr, delim) == nullptr){
            fputs(temp, F2);
            fputc('\n', F2);
        }
    }

    fclose(F1);
    fclose(F2);
}

int longestWord(){

FILE *F2 = fopen("F2.txt", "r");

char temp[100];

fgets(temp, sizeof(temp), F2);
int len = strlen(temp);
if (len > 0 && temp[len - 1] == '\n') {
        temp[len - 1] = '\0';
    }
int longest = strlen(temp);
int k = 0;
for(int i = 1; i < 10; ++i){
    fgets(temp, sizeof(temp), F2);
    size_t len = strlen(temp);
    if (len > 0 && temp[len - 1] == '\n') {
        temp[len - 1] = '\0';
    }
    if(strlen(temp) > longest){
        longest = strlen(temp);
        k = i;
    }
}
fclose(F2);
return k + 1;
}

int main(){

fileFill();
copy();
int result = longestWord();
std::cout  << "Longest word index: " <<result;
    return 0;
    }