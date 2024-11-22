#include <iostream>
#include <cstdio>
#include <cstring>

enum FileOpResult {
    Success=1,
    Failure=0
};

FileOpResult write_to_file(const char* name, char* content) {
    FILE* f = fopen(name, "a");
    if (!f) {
        printf("Failure to open file for writing!\n");
        return Failure;
    }
    fputs(content, f);
    fputs("\n", f);
    fclose(f);

    FILE* nf = fopen(name, "r");
    if (!nf) {
        printf("Failure to open file for reading!\n");
        return Failure;
    }

    printf("\nWould you like to see the file? (y/n): ");
    char ans;
    std::cin >> ans;

    if (ans == 'y') {
        printf("\nHere is the file content:\n");
        char string[255];
        while (fgets(string, sizeof(string), nf)) {
            printf("%s", string);
        }
    }

    fclose(nf);
    return Success;
}


FileOpResult copy_file(const char* file_from, const char* file_to){
    FILE* f = fopen(file_from, "r");
    if (!f) {
        printf("Failure to open file for writing!\n");
        return Failure;
    }
    FILE* nf = fopen(file_to, "w");
    if (!nf) {
        printf("Failure to open file for writing!\n");
        return Failure;
    }
    char string[255];
    while (fgets(string, sizeof(string), f)) {
            fputs(string, nf);
    }
    fclose(f);
    fclose(nf);
    return Success;
}




int main() {
    const char* name = "MyFile.txt", *file_from = "MyFile.txt", *file_to = "NewFile.txt";
    char answer;
    bool result1, result2;

    FILE* f = fopen(name, "w");
    if (f){
        fclose(f);
    } 

    printf("\nWould you like to write to the file? (y/n): ");
        std::cin >> answer;
        std::cin.ignore();
Function :
        if (answer == 'y') {
            printf("Enter your string: ");
            char content[255];
            std::cin.getline(content, sizeof(content));
            write_to_file(name, content);
        } else {
           printf("Successfull writing into the file!");
            goto Second;
        }

        printf("\nWould you like to continue? (y/n): ");
        std::cin >> answer;
        std::cin.ignore();
    goto Function;

Second :

    if(copy_file(file_from, file_to)){
        printf("\nSuccessfull copying!");
    } else {
        printf("\nFailed to copy");
    } 

    return 0;
}