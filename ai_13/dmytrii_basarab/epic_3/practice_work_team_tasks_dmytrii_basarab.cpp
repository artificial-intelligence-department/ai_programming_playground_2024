#include <iostream>
#include <vector>
#include<string>

using namespace std;

    const vector<string> book = {"book1", "book2", "book3"};

int main() {
    int input = 1;
    string name_take;
    vector<bool> available = {1, 1, 1};
    
while (input != 0) {
menu:

    cout << "Меню" << endl;
    cout << " Перерахувати книги(1)\n Взяти книгу(2)\n Повернути книгу(3)\n Вихід(0)\n ";
    cin >> input;


    if (input == 1) {

            
            for (int i = 0; i < book.size(); i++) {
                cout << book[i] << "\t ";
            }
        cout << endl;


            for (bool stan : available) {
                if (stan == 1) {
                    cout << "Доступна" << " ";
                } else {
                    cout << "Недоступна" << " ";
                }
            }
        cout << endl;


        do {
        cout << "Ще щось?(будь-яке число)\nЦе все(0)\n";
        cin >> input;  
        if (input == 0) {
            return 0;
        } 

            } while (input == 0);


            goto menu;



    } else if (input == 2) {

            cout << "Яку книжку хочете взяти?: ";
            cin >> input;

            if (input <= book.size() && input > 0) {
                if (available[input - 1] == 1) {
                    available[input - 1] = 0;
                    cout << "Ви взяли" << endl;
                } else {
                    cout << "Її нема" << endl;
                }
            } else {

                goto menu;
            }   


            do {
        cout << "Ще щось?(будь-яке число)\nЦе все(0)\n";
        cin >> input;   

        if (input == 0) {
            return 0;
        } 

            } while (input == 0);


            goto menu;    



    } else if (input == 3) {
            cout << "Яку книжку хочете повернути?: ";
            cin >> input;
            if (input > 0 && input <= book.size()) {
                if (available[input - 1] == 0) {
                    available[input - 1] = 1;
                    cout << "Ви повернули" << endl;
                } else {
                    cout << "Вона є" << endl;
                }
            } else {
                goto menu;
            }
            do {
        cout << "Ще щось?(будь-яке число)\nЦе все(0)\n";
        cin >> input;  
        if (input == 0) {
            return 0;
        } 
            } while (input == 0);
            goto menu;            
        }
}
    return 0;
}