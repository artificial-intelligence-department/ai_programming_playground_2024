#include <iostream>

using namespace std;

//створюмо перерахунок для результату нашої операції
enum FileOpResult { Success, Failure}; 

//функція для копіювання вмісту одного файлу в інший
FileOpResult copy_file(char *file_from, char *file_to){
    //перевірка наявності їм'я файлів
    if (file_from == nullptr || file_to == nullptr){
        cout << "Error, no filenames provided";
        return Failure;
    }
    
    //перевірка чи файли відкрилися
    FILE *file_1 = fopen(file_from, "r");
    if (!file_1) {
        cout << "Error while opening the file " << file_from << endl;
        return Failure;
    }
    FILE *file_2 = fopen(file_to, "w");
    if (!file_2) {
        cout << "Error while opening the file " << file_to <<  endl;
        return Failure;
    }

    //порядковий запис файлу 1 у файл 2 з перевіркою на помилку
    char f1_line[256];
    while(fgets(f1_line, sizeof(f1_line), file_1) != nullptr)
    {
        if(fputs(f1_line, file_2) == EOF){
            cout << "Error while writing to file " << file_to << endl;
            fclose(file_1);
            fclose(file_2);
            return Failure;
        }
    }

    //перевірка чи закрилися файли
    if(fclose(file_1) != 0){
        cout << "Error while closing the file " << file_from << endl;
        return Failure;
    }
    if(fclose(file_2) != 0){
        cout << "Error while closing the file " << file_to << endl;
        return Failure;
    }
    return Success;
}

int main() {
    //створюємо змінні з двома іменами файлів
    char file_from[64] = "file_from.txt";
    char file_to[64] = "file_to.txt";

    //виклик функції і запис резутату
    enum FileOpResult result = copy_file(file_from, file_to);

    //опрацювання результату
    if(result == 0){
        cout << "The operation is successful";
    }
    else{
        cout << "The operation failed";
    }
    return 0;
}