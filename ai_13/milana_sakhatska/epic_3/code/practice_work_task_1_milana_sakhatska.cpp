#include <iostream>   
#include <vector>     
#include <string>     

using namespace std;  

int main() {
  
    vector<string> books = {"Гаррі Поттер", "Володар Перснів", "Війна і мир", "1984"};
    vector<bool> available = {true, true, true, true};  

    int choice;  
    string bookName;  
    bool continueProgram = true; 

    do {
        
        cout << "Меню:\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Введіть свій вибір: ";
        cin >> choice;  

       
        switch (choice) {
            case 1: {  
                cout << "Список книг:\n";
                for (int i = 0; i < books.size(); i++) {  
                    cout << (i + 1) << ". " << books[i] << " - " 
                         << (available[i] ? "Доступна" : "Взята") << endl;
                }
                break;
            }
            case 2: { 
                cout << "Введіть назву книги, яку хочете взяти: ";
                cin.ignore(); 
                getline(cin, bookName);  
                bool found = false;  

         
                for (int i = 0; i < books.size(); i++) {
                    if (books[i] == bookName) {
                        found = true;
                        if (available[i]) {
                            available[i] = false;  
                            cout << "Ви взяли книгу: " << books[i] << endl;
                        } else {
                            cout << "Вибачте, книга вже взята.\n";
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "Книга не знайдена.\n";
                }
                break;
            }
            case 3: { 
                cout << "Введіть назву книги, яку хочете повернути: ";
                cin.ignore();  
                getline(cin, bookName);  
                bool found = false;  

               
                for (int i = 0; i < books.size(); i++) {
                    if (books[i] == bookName) {
                        found = true;
                        if (!available[i]) {
                            available[i] = true; 
                            cout << "Ви повернули книгу: " << books[i] << endl;
                        } else {
                            cout << "Ця книга вже доступна.\n";
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "Книга не знайдена.\n";
                }
                break;
            }
            case 4: {  
                continueProgram = false;  
                cout << "Дякуємо за користування бібліотекою!\n";
                break;
            }
            default: 
                cout << "Неправильний вибір! Спробуйте ще раз.\n";
                break;
        }

       
        if (continueProgram) {
            cout << "Чи бажаєте виконати іншу операцію? (1 - Так, 0 - Ні): ";
            cin >> continueProgram;  
        }

    } while (continueProgram);  

    return 0;  
}

