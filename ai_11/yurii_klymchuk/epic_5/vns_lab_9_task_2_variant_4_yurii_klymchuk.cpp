#include <iostream>
#include <cstring>

using namespace std;

//створюємо перший файл
void CreateFirstFile(const char* filename_1, const char** content){
    FILE *file_1 = nullptr;
    file_1 = fopen(filename_1, "w");
    if (file_1 == nullptr){
        cerr << "Failed to open a file";
        return;
    }

    for (int i = 0; i < 10; i++){
        fputs(content[i], file_1);
    }
    fclose(file_1);
}
//записуємо у другий файл стрічки з 1 починаючи з 4-тої
void CreateSecondFile(const char* filename_1, const char* filename_2){
    FILE *file_1 = nullptr;
    file_1 = fopen(filename_1, "r");
    if (file_1 == nullptr){
        cerr << "Failed to open the first file\n";
        return;
    }

    FILE *file_2 = nullptr;
    file_2 = fopen(filename_2, "w");
    if (file_2 == nullptr){
        cerr << "Failed to open the second file\n";
        fclose(file_1);
        return;
    }

    char f1_line[256];
    int line_index = 1;
    while(fgets(f1_line, sizeof(f1_line), file_1) != nullptr)
    {
        if(line_index >= 4)
        {
            fputs(f1_line, file_2);
        }
        line_index++;
    }

    fclose(file_1);
    fclose(file_2);

}
//рахуємо символи в отанньому слові 2 файлу
void CountSymbols(const char* filename_2){
    FILE *file_2 = nullptr;
    file_2 = fopen(filename_2, "r");
    if (file_2 == nullptr){
        cerr << "Failed to open the second file\n";
        return;
    }

    char f2_line[256];
    char* last_word;
    int index = 1;

    while(fgets(f2_line, sizeof(f2_line), file_2) != nullptr);
    char* lastSpace = strrchr(f2_line, ' ');
    last_word = lastSpace + 1;
    cout << "The number of symbols in last word of the second file is " << strlen(last_word);  
}
int main(){
    //створюємо змінні для назв файлів та тексту
    const char* filename_1 = "vns_lab9_file1.txt";
    const char* filename_2 = "vns_lab9_file2.txt";
    const char* file_1_content[10] = {
        "I would say I'm sorry\n",
        "If I thought that it would change your mind\n",
        "But I know that this time\n",
        "I have said too much\n",
        "Been too unkind\n",
        "I tried to laugh about it\n",
        "Cover it all up with lies\n",
        "I tried to laugh about it\n",
        "Hiding the tears in my eyes\n",
        "Cause boys don't cry"
    };
    //по черзі викликаємо необхідні функції
    CreateFirstFile(filename_1, file_1_content);
    CreateSecondFile(filename_1, filename_2);
    CountSymbols(filename_2);
    return 0;
}