#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name,const char *content){
    if(name == NULL || content == NULL){
        cout<<"Неправильна назва файлу або вмісту!"<<endl;
        return Failure;
    }

ofstream file(name);

if(!file.is_open()){
    cout<<"Не вдалось відкрити файл!"<<endl;
    return Failure;
}

file<<content;
if(!file){
    cout<<"Помилка запису"<<endl;
    file.close();
    return Failure;
}


file.close();
if(file.fail()){
    cout<<"Помилка закриття файлу"<<endl;
    return Failure;
}else{
return Success;
}
}
int main(){
    char filename[1024];
    char content[1024];
    cin.getline(filename,1024);
    cin.getline(content,1024);
    FileOpResult result = write_to_file(filename, content);

    if(result == Success){
        cout<<"Все записано успішно!"<<endl;
    }
    else{
        cout<<"На жаль, не вдалось записати зміст!("<<endl;
    }
    return 0;

}