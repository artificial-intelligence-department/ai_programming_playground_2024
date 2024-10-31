 #include <iostream>
 #include <vector>
 #include <cctype>

 using namespace std;

 void borrowBook();
 void returnBook();
 void listAllBooks();


 vector<string> books = {"Book1", "Book2", "Book3", "Book4"};
 vector<bool> isAvailable = {true, true, true, true};

 int main(){
    bool exit = false;

    while (!exit) {
        menu: 

        int choice;

        cout << "\nМеню:\n";
        cout << "1 Позичити книгу\n";
        cout << "2 Повернути книгу\n";
        cout << "3 Перерахувати всі книги\n";
        cout << "4 Вийти\n";
        cout << "Я хочу: ";

        cin >> choice;

        switch (choice) {
            case 1:
                borrowBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                listAllBooks();
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Такої функції в нашій бібліотеці нема ;)\n";
                goto menu;
        }

        char anotherOperation;
        do {
            cout << "\nХочете виконати іншу операцію? (y/n): ";
            cin >> anotherOperation;
        } while (tolower(anotherOperation) != 'y' && tolower(anotherOperation) != 'n');

        if (tolower(anotherOperation) == 'n') {
            exit = true;
        }
    }
 }

    void listAllBooks(){
        cout << "Список книг: \n";

        for(int i = 0; i < books.size(); i++){
            cout << i+1 << " " << books[i];
            if(isAvailable[i]){
                cout << "   В наявності\n";
            }else{
                cout << "   Не в наявності\n";
            }
        }
    }

    void borrowBook() {
    int num;
    listAllBooks();
    cout << "\nВведіть номер книги, яку бажаєте взяти: ";
    cin >> num;

    if (num < 1 || num > books.size()) {
        cout << "Такої книги нема.\n";
        goto menu;
    }

    if (isAvailable[num - 1]) {
        isAvailable[num - 1] = false;
        cout << "Ви взяли книгу: " << books[num - 1] << "\n";
    } else {
        cout << "Книги нема наявності.\n";
    }

    menu:

    return;

    }

    void returnBook(){
        listAllBooks();
        int num;
        cout << "\nВведіть номер книги, яку бажаєте повернути: ";
        cin >> num;

        if (num < 1 || num > books.size()) {
        cout << "Такої книги нема.\n";
        goto menu;
        }

        if(!isAvailable[num - 1]) {
            isAvailable[num - 1] = true;
            cout << "Ви повернули книгу: " << books[num - 1] << "\n";
    } else {
        cout << "Цю книгу ніхто не позичав, щоб повертати.\n";
    }

    menu:

    return;
    }