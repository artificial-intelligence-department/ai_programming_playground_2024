#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure_create, Failure_open, Failure_write};
FileOpResult copy_file(const char *file_from, const char *file_to){

    ifstream file1(file_from);
    if (!file1.is_open()){
        return Failure_open;
    }

    ofstream file2(file_to);
    if (!file2.is_open()){
        cerr << "2";
        return Failure_create;
    }

    file2 << file1.rdbuf();
    if (file2.fail()){
        cerr << "3";
        return Failure_write;
    }

    file1.close();
    file2.close();

    return Success;
}

int main(){
    const char* filename1 = "file_from.txt";
    const char* filename2 = "file_to.txt";

    FileOpResult res = copy_file(filename1, filename2);

    if(res == Success){
        cout << "Копіювання даних у файл пройшло успішно"; 
    }
    else if(res == Failure_create){
        cout << "Не вдалося відкрити або створити вихідний файл";
    }
    else if(res == Failure_open){
        cout << "Не вдалося відкрити вхідний файл";
    }
    else if(res == Failure_write){
        cout << "Помилка під час запису даних у файл";
    }

    return 0;
}


