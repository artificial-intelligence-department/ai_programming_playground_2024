// 13.
//Створити текстовий файл F1 не менше, ніж з 10 рядків і записати в нього
//інформацію
// 1) Скопіювати з файлу F1 у файл F2 всі рядки, що починаються на букву «А» і
// розташовані між рядками з номерами N1 й N2.
// 2) Визначити номер того рядка, у якому найбільше приголосних букв, файлу
// F2.

#include <iostream>


void Find(const char* filename){
    FILE* f = fopen(filename, "r");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    int i=1, k=0, answer;
    int count=0;
    char string[50];
    while(fgets(string, 50, f)){
        for(int j=0; j<sizeof(string); j++){
            if(string[j]!='a' || string[j]!='e' || string[j]!='y' ||
            string[j]!='u' || string[j]!='i' || string[j]!='o' ||
            string[j]!=' ' || string[j]!='\''|| string[j]!='.' || string[j]!='?' || 
            string[j]!='!' || string[j]!=':'){
                count++;
            }
            if(count>k){
                k=count;
                answer = i;
            }
        }
        i++;
    }
    printf("\nThe most of consonants are in %i row", answer);
    fclose(f);
}

void Print(const char* filename){
    FILE* f = fopen(filename, "r");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    char string[50];
    while(fgets(string, 50, f)){
        printf("%s",string);
    }
    fclose(f);
}


void Transfer(int N1, int N2){
    FILE* F1=fopen("File 1.txt","r");
    FILE* F2=fopen("File 2.txt", "w");
    char string[50];
    for(int i=0; fgets(string, 50, F1)!=0; i++){
        if(string[0]=='A' && i>=N1-1 && i<=N2-1){
            fputs(string, F2);
        }
    }
    // while(fgets(string, 50, F1)){
    //     if(string[0]=='A'){
    //         fputs(string, F2);
    //     }
    // }
    fclose(F1);
    fclose(F2);
}

int main(){
    int N1=1, N2=7;
    FILE* F1=fopen("File 1.txt","w");
    if(F1==0){
        std::cerr << "Cannot open file №1";
        return 0;
    }
    fputs("Answer me that : do you like to sing?", F1);
    fputs("\nAnd what is your favourite song?", F1);
    fputs("\nAngel, nothing is better than this : ", F1);
    fputs("\nWe\'re no strangers to love", F1);
    fputs("\nYou know the rules and so do I", F1);
    fputs("\nA full commitment\'s what I'm thinkin\' of", F1);
    fputs("\nYou wouldn\'t get this from any other guy", F1);
    fputs("\nI just wanna tell you how I\'m feeling", F1);
    fputs("\nGotta make you understand", F1);
    fputs("\nNever gonna give you up", F1);
    fputs("\nNever gonna let you down", F1);
    fputs("\nNever gonna run around and desert you", F1);
    fputs("\nNever gonna make you cry", F1);
    fputs("\nNever gonna say goodbye", F1);
    fputs("\nNever gonna tell a lie and hurt you", F1);
    fputs("\nWe\'ve known each other for so long", F1);
    fputs("\nYour heart\'s been aching, but you're too shy to say it", F1);
    fputs("\nInside, we both know what\'s been going on", F1);
    fputs("\nWe know the game and we\'re gonna play it", F1);
    fputs("\nAnd if you ask me how I\'m feeling", F1);
    fputs("\nDon\'t tell me you're too blind to see", F1);
    fputs("\nWe\'ve known each other for so long", F1);
    fputs("\nYour heart\'s been aching, but you're too shy to say it", F1);
    fputs("\nInside, we both know what's been going on", F1);
    fputs("\nWe know the game and we're gonna play it", F1);
    fclose(F1);
    printf("Here is the first file : \n\n");
    Print("File 1.txt");
    Transfer(N1, N2);
    printf("\n\nHere is the second file : \n\n");
    Print("File 2.txt");
    Find("File 2.txt");
    return 0;
}