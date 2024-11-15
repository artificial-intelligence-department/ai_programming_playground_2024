#include <iostream>
#include <string>
#include <vector>

using namespace std;

//створюємо список книг і вказуємо які з них наявні
vector<string> books{
    "1.The Metamorphosis",
    "2.Martin Eden",
    "3.The magdalen martyrs",
    "4.Puzzle",
    "5.451 degrees Fahrenheit"
};
vector<bool> available_books{true, false, false, true, false};

int main(){
    while(true){//основний цикл
        do{//підцикл
            tryAgain:
            int task_choice;
            cout << "Welcome to the library!\nWhat can we do for you:"<<
            "\n1.List all the books"<<
            "\n2.List available books"<<
            "\n3.Take the book"<<
            "\n4.Return the book"<<
            "\n5.Leave the library"<<
            "\nYour choice:";
            cin >> task_choice;
            switch(task_choice){//опрацьовуємо ввід користувача
                case 1:{
                    cout << "The list of all books:" << endl;
                    for (int i = 0; i < books.size(); i++){
                        cout << books[i] << endl;
                    }
                    
                }break;
                case 2:{
                    cout << "Available books:" << endl;
                    int k = 0;
                    for(string i : books){
                        if (available_books[k]){
                            cout << i << " is available\n";
                        }
                        k++;
                    }
                }break;
                case 3:{
                    int user_input;
                    cout << "Enter the index of a book you want to take: ";
                    cin >> user_input;
                    if (user_input < 1 || user_input > books.size()){
                        cout << "Your option isn`t valid\n";
                        break;
                    }
                    if (available_books[user_input-1]){
                        available_books[user_input-1] = false;
                        cout << books[user_input-1] << " is available. You can take it\n";
                    }
                    else{
                        cout << books[user_input-1] << " isn`t available\n";
                    };
                }break;
                case 4:{
                    int returning;
                    cout << "Enter the index of a book you want to return: ";
                    cin >> returning;
                    if (returning < 1 || returning > books.size()){
                        cout << "Your option isn`t valid\n";
                        break;
                    }
                    if (available_books[returning-1]){
                        cout << "This book is already here. There must be a mistake\n";
                    }
                    else{
                        available_books[returning-1] = true;
                        cout << "Thank you for returning the book\n";
                    };
                }break;
                case 5:
                    goto leave;//перескакуємо на елемент коду з запитання про вихід
                default:
                    cout << "Your option isn`t on the list\n";
            }
            ask:
            char user_input;
            cout << "Anything else?(y/n):";
            cin >> user_input;
            if (user_input == 'y' || user_input == 'Y'){
                goto tryAgain;//відправляємо користувача назад на початок підциклу
            }
            else if (user_input == 'n' || user_input == 'N'){
                cout << "Okey\n";
                break;//виходимо з підциклу
            }
            else{
                cout << "Answer clearly\n";
                goto ask;//перепитуємо через неправильно уведену відповідь
            }
        }while(true);
        leave:
        char user_input;
        cout << "Do you want to leave?(y/n):";
        cin >> user_input;
        if (user_input == 'y' || user_input == 'Y'){
            cout << "Thank you for visiting";
            return 0;//кінець програми
        }
        else if (user_input == 'n' || user_input == 'N')
        {
            cout << "Stay as long as you need\n";
            goto tryAgain;//відправляємо користувача назад на початок підциклу
        }
        else{
            cout << "Answer clearly\n";
            goto leave;//перепитуємо через неправильно уведену відповідь
        }
    }
}