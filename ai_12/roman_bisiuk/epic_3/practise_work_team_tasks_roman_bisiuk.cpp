#include <iostream>
#include <vector>

using namespace std;

void booksList();
void borrowBook();
void returnBook();

vector<string> bookNames = {"Bible", "Harry Potter", "Sentimental story", "Berserk", "Vinland saga"};
vector<bool> isAvailable = {true, true, true, true, false};

int main()
{
    int choice;
    do{
        cout << "*****************************" << endl;
        cout << "Меню:" << endl;
        cout << "1. Переглянути усі книги:" << endl;
        cout << "2. Позичити книгу" << endl;
        cout << "3. Повернути книгу" << endl;
        cout << "4. Вийти" << endl;
        cout << "****************************" << endl;
        cout << "Введіть свій вибір:  ";
        cin >> choice;
        
        switch(choice){
            case 1:
                booksList();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                cout << "Дякуюємо за візит";
                break;
            default: 
                cout<< "Такої функції не існує" << endl;
        }
    }while(choice != 4);

}

void booksList(){
    cout << "Список книг: " << endl;
    for(int i = 0; i < bookNames.size(); i++){
        cout << i+1 << " " << bookNames[i];
        if(isAvailable[i]){
            cout << "  В наявності" << endl;
        }else{
            cout << "  Не в наявності" << endl;
        }

    }
};

void borrowBook(){
    int num;
    retry:
    booksList();
    cout << "Введіть номер книги, яку хочете взяти: " << endl;
    cin >> num;
    if(num < 1 || num > bookNames.size()){
        cout << "Цієї книги немає в бібліотеці" << endl;
        goto retry;
    }
    if(isAvailable[num - 1]){
        isAvailable[num - 1] = false;
        cout << "Ви взяли книгу " <<bookNames[num -1] << endl;
    }else{
        cout << "Книги немає в наявності" <<endl;
        goto retry;
    }
    
};

void returnBook(){
    int num;
    retry:
    booksList();
    cout << "Введіть номер книги, яку хочете повернути: " << endl;
    cin >> num;
    if(num < 1 || num > bookNames.size()){
        cout << "Цієї книги немає в бібліотеці" << endl;
        goto retry;
    }
    if(!isAvailable[num - 1]){
        isAvailable[num - 1] = true;
        cout << "Ви повернули книгу " << bookNames[num -1] << endl;
    }else{
        cout << "Книга не була позичена " <<endl;
        goto retry;
    }

};



