#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure_create, Failure_open, Failure_write}; 
FileOpResult write_to_file(char *name, char *content){

    if (name == nullptr){
        return Failure_create;
    }

    ofstream file(name);
    if (!file.is_open()) {
        return Failure_open;
    }

    file << content;

    if(file.fail()){
        return Failure_write;
    }

    file.close();
    return Success;
}

int main(){
    char filename[124];
    char content[1024];

    cout << "Enter filename: ";
    cin.getline(filename, 100);

    cout << "Enter content: ";
    cin.getline(content, 1000);

    FileOpResult res = write_to_file(filename, content);

    if(res == Success){
        cout << "Запис даних у файл пройшов успішно"; 
    }
    else if(res == Failure_create){
        cout << "Не вдалося створити файл: відсутня назва";
    }
    else if(res == Failure_open){
        cout << "Помилка при відкритті файлу";
    }
    else if(res == Failure_write){
        cout << "Помилка під час запису даних у файл";
    }

    return 0;
}

