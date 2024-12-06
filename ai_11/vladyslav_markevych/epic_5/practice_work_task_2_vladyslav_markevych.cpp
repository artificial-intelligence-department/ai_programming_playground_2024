#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure};
FileOpResult copy_file(const char *file_from,const char *file_to){
    if(file_from == NULL || file_to == NULL){
        cout<<"Щось пішло не так!"<<endl;
        return Failure;
    }

   ifstream fileto(file_from, ios::binary);  
if(!fileto.is_open()){
    cout<<"Не вдалось відкрити файл!"<<endl;
    return Failure;
}

    ofstream filefrom(file_to, ios::binary);
if(!filefrom.is_open()){
    cout<<"Не вдалось відкрити файл!"<<endl;
    return Failure;
}


filefrom << fileto.rdbuf();

if(!filefrom){
    cout<<"Не вдалось прочитати файл!"<<endl;
    return Failure;
}

fileto.close();
filefrom.close();
return Success;

}
int main(){
char filein[1024];
char fileout[1024];

cin.getline(filein,1024);
cin.getline(fileout,1024);


FileOpResult finalresult = copy_file (filein, fileout);
 if(finalresult == Success){
        cout<<"Все записано успішно!"<<endl;
    }
    else{
        cout<<"На жаль, не вдалось записати зміст!("<<endl;
    }

return 0;
}