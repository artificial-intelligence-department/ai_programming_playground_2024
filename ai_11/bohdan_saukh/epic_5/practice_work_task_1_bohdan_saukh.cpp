#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(char *name, char *content){
    if (name == nullptr || content == nullptr || strlen(name) == 0){
        return Failure;
    }

    ofstream file(name, ios::out | ios::trunc);
    if (!file.is_open()){
        return Failure;
    }

    file << content;
    if (file.fail()){
        file.close();
        return Failure;
    }

    file.close();
    if (file.is_open()){
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to){
    if (file_from == nullptr || file_to == nullptr || strlen(file_from) == 0 || strlen(file_to) == 0){
        return Failure;
    }

    ifstream src(file_from, ios::in | ios::binary);
    if (!src.is_open()){
        return Failure;
    }

    ofstream dest(file_to, ios::out | ios::trunc | ios::binary);
    if (!dest.is_open()){
        src.close();
        return Failure;
    }

    dest << src.rdbuf();

    if (dest.fail() || src.fail()){
        src.close();
        dest.close();
        return Failure;
    }

    src.close();
    dest.close();

    if (src.is_open() || dest.is_open()){
        return Failure;
    }

    return Success;
}

int main(){
    char filename[100];
    char content[10000];

    cout << "Введіть ім'я файлу: ";
    cin.getline(filename, 100);

    cout << "Введіть вміст файлу: ";
    cin.getline(content, 10000);

    FileOpResult result = write_to_file(filename, content);

    if (result == Success){
        cout << "Файл успішно створено та записано." << endl;
    }else{
        cout << "Сталася помилка при створенні або запису файлу." << endl;
    }
    
    char source_file[10000];
    char destination_file[10000];

    cout << "Введіть ім'я файлу-джерела: ";
    cin.getline(source_file, 10000);

    cout << "Введіть ім'я файлу-призначення: ";
    cin.getline(destination_file, 10000);

    result = copy_file(source_file, destination_file);

    if (result == Success){
        cout << "Файл успішно скопійовано." << endl;
    }else{
        cout << "Сталася помилка під час копіювання файлу." << endl;
    }

    return 0;
}
