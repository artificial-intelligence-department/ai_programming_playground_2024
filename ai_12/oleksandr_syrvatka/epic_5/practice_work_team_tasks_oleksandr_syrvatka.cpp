#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(const char *name, const char *content){
    // if (name == nullptr || strcmp(name, "") == 0 || !hasEnding(name, ".txt")) {
    //     return FileOpResult::Failure;
    // }
    FILE* fileStream;
    fileStream = fopen(name, "w");
    if (fileStream == nullptr){
        cerr << "Не вдалося cтворити файл";
        return FileOpResult::Failure;
    }
    fputs(content, fileStream);
    fclose(fileStream);
    return FileOpResult::Success;
}
FileOpResult copy_file(const char *file_from, const char *file_to){
    // if (name == nullptr || strcmp(name, "") == 0 || !hasEnding(name, ".txt")) {
    //     return FileOpResult::Failure;
    // }
    FILE* fileStream1;
    fileStream1 = fopen(file_from, "r");
    if (fileStream1 == nullptr){
        cerr << "Не вдалося cтворити файл";
        return FileOpResult::Failure;
    }
    FILE* fileStream2;
    fileStream2 = fopen(file_to, "w");
    if (fileStream2 == nullptr){
        cerr << "Не вдалося cтворити файл";
        fclose(fileStream1);
        return FileOpResult::Failure;
    }
    const int size= 64;
    char arr[size];
    while(fgets(arr, size, fileStream1)){
        fputs(arr, fileStream2);
    }
    fclose(fileStream1);
    fclose(fileStream2);
}


int main() {
    string name, content;
    cin >> name;
    cin >> content;
    const char* namec = name.c_str();
    const char* contentc = content.c_str();
    string file_from, file_to;
    cin >> file_from;
    cin >> file_to;
    const char* file_fromc = file_from.c_str();
    const char* file_toc = file_to.c_str();
   // write_to_file(namec, contentc);
    copy_file(file_fromc, file_toc);
    return 0;
}
