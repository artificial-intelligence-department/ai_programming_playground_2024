#include <iostream>

using namespace std;

//створюмо перерахунок для результату нашої операції
enum FileOpResult { Success, Failure}; 

//функція типу нашого перерахунку для запису тексту у файл
FileOpResult write_to_file(char *name, char *content){
    //перевірка наявності їм'я файлу та тесту
    if (name == NULL || content == NULL){
        cout << "Error, no filename or content provided.\n";
        return Failure;
    }
    //перевірка чи файл відкрився
    FILE *file = fopen(name, "w");
    if (!file) {
        cout << "Error opening file\n";
        return Failure;
    }
    //перевірка чи записався текст у файл
    fwrite(content, sizeof(content), 1, file);
    if (file == NULL){
        cout << "Error while writing content into file.\n";
        return Failure;
    }

    //перевірка чи записався текст у файл
    if (fputs(content, file) == EOF){
        cout << "Error while writing content into file.\n";
        fclose(file);
        return Failure;
    }

    //перевірка чи закрився файл
    if(fclose(file) != 0){
        cout << "Error while closing the file \n";
        return Failure;
    }
    return Success;
}

int main() {
    //змінні для назви файлу та вмісту
    char filename[255];
    char file_content[1000];

    cout << "Enter the file name: ";
    cin >> filename;

    cout << "Enter the content of the file: ";
    cin >> file_content;

    //виклик функції і запис резутату
    enum FileOpResult result = write_to_file(filename, file_content);

    //опрацювання результату
    if(result == 0){
        cout << "The operation is successful";
    }
    else{
        cout << "The operation failed";
    }
    return 0;
}