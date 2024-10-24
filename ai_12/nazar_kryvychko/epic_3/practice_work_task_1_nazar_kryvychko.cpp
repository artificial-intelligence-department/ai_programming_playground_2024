#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
   vector<string> books = { "Book1", "Book2", "Book3", "Book4" };
   vector<bool> availability = { true, true, true, true };

   int option;

mainMenu:
   cout << "\nМеню:\n";
   cout << "1. Перерахувати всі книги\n";
   cout << "2. Взяти книгу\n";
   cout << "3. Повернути книгу\n";
   cout << "4. Вийти\n";
   cout << "Оберіть опцію: ";
   cin >> option;

   switch (option) {
   case 1: {
       cout << "Список книг:\n";
       for (size_t i = 0; i < books.size(); i++) {
           cout << (i + 1) << ". " << books[i] << (availability[i] ? " (Доступна)" : " (Не доступна)") << endl;
       }
       break;
   }
   case 2: {
       int choice;
       cout << "Введіть номер книги, яку хочете взяти: ";
       cin >> choice;

       if (choice < 1 || choice > books.size() || !availability[choice - 1]) {
           cout << "Неправильний вибір або книга недоступна.\n";
           goto mainMenu; 
       }

       availability[choice - 1] = false;
       cout << "Ви позичили '" << books[choice - 1] << "'\n";
       break;
   }
   case 3: {
       int choice;
       cout << "Введіть номер книги, яку хочете повернути: ";
       cin >> choice;

       if (choice < 1 || choice > books.size() || availability[choice - 1]) {
           cout << "Неправильний вибір або книга не була позичена.\n";
           goto mainMenu; 
       }

       availability[choice - 1] = true;
       cout << "Ви повернули '" << books[choice - 1] << "'\n";
       break;
   }
   case 4:
       cout << "Вихід...\n";
       return 0; 
   default:
       cout << "Неправильний вибір, спробуйте ще раз.\n";
       goto mainMenu; 
   }

   cout << "Бажаєте виконати іншу операцію? (1 - Так, 0 - Ні): ";
   int anotherOperation;
   cin >> anotherOperation;

   if (anotherOperation == 1) {
       goto mainMenu; 
   }

   return 0;
}
