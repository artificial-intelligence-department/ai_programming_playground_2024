#include <iostream>
#include <fstream>                                                                                         

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult createFile(char name[], char text[])
{
    if (name==nullptr || text==nullptr) {
        cout << "Нема тексту або назви файла" <<endl;
        return Failure;
    }

        FILE* fp;
        fp = fopen(name, "w");
        
    if (fp==nullptr) {//fopen поверьає 0 якшо успішно і EOF якшо помилка
        cout << "Не вдалося відкрити файл" << endl;
    }


        while (*text) {//берем адресу тексту і розіменовуємо false буде при \0
            putc(*text, fp);
            text++;//арифметика визначників шо якшо ми додаєм 1 то адреса переноситься на +1 байт якшо то char 

        }
    
        if (fclose(fp)==EOF) {
            cout << "Не вийшло закрити файл" << endl;
            return Failure;
        }
    
    return Success;
}

int main()
{
    char name[50];
    char text[1000];
    cout << "Напишіть назву файлу: ";
    cin.getline(name, 50);//зчитує допоки є 49 символів бо один цн \0 або до ентер

    cout << "Напишіть текст: ";
//cin >> name зчитує все до першого пробілу тому не юзаєм тут
    cin.getline(text, 1000);

    FileOpResult res = createFile(name, text);
    if(res == Success)
    {
        cout << "Все успішно" << endl;
    }
    else
    {
        cout << "Помилка" << endl;
    }
    
            //cout << &text << endl;
            //cout << *(text+1) << endl;


        return 0;
    
}