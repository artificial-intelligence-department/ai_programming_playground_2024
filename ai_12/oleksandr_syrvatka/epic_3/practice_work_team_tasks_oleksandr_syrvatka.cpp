#include <iostream>
#include <vector>
#include <string>

using namespace std;

void list(vector<string> &Booklist){
    cout << "Список книг: ";
    for (int i = 0; i < Booklist.size(); i++){
    cout << Booklist[i] << " , ";
    }
    cout <<"\b\b .\n";
}

void CheckList(vector<string> &Booklist,vector <bool> &availability){
    int i = 0;
    for(auto book:Booklist){
        cout << Booklist[i];
        if (availability[i]){
            cout << " є у наявності\n";
        }
        else{
            cout << " відсутня\n";
        }
        i++;
    }
}

void Borrow(vector<string> &Booklist,vector <bool> &availability){
    int booknumber = 0;
    cout << "Введіть номер книги яку хочете позичити: ";
    cin >> booknumber;
    if (availability[(booknumber-1)]){
        cout << "Ви взяли книгу " << booknumber << "\n";
        availability[(booknumber-1)] = false;
    }
    else{
        cout << "Книга відсутня\n";
    }
}

void Return (vector<string> &Booklist,vector <bool> &availability){
    int booknumber = 0;
    cout << "Введіть номер книги яку хочете повернути: ";
    cin >> booknumber;
    if (!availability[(booknumber-1)]){
        cout << "Ви повернули книгу " << booknumber <<"\n";
        availability[(booknumber-1)] = true;
    }
    else{
        cout << "Книга уже є у бібліотеці\n";
    }
}

int main(){
    vector<string> Booklist{"Книга 1", "Книга 2","Книга 3","Книга 4","Книга 5"};
    vector <bool> availability{true,true,true,true,true};
    char answer, choice;
        do {
            menu:
            answer == 'n';
            cout << "Меню:\n1)Список книг \n2)Перевірити наявність усіх книг \n3)Позичити книгу \n4)Повернути книгу\n5)Покинути бібліотеку\n ";
            cin >> choice;
            switch(choice){
                case '1': 
                    list(Booklist);
                    break;
                case '2':
                    CheckList(Booklist,availability);
                    break;
                case '3':
                    Borrow(Booklist,availability);
                    break;
                case '4':
                    Return(Booklist,availability);
                    break;
                case '5':
                    break;
                default :
                    cout << "Введенно неправильне значення \n";
                    goto menu;
                    break;   
            }
            if (choice != '5') {
                cout << "Ви хочете зробити ще дію? (y/n): ";
                cin >> answer;
            }
         
    }while (answer == 'y' && choice !='5');
    cout << "Ви покинули бібліотеку";
    
    return 0;
}