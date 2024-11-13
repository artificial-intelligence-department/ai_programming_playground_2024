#include <iostream>
#include <vector>
#include <string>
using namespace std;

void enumerate(vector <string> &bookList, vector <bool> &exist){
    for (int i = 0; i < exist.size(); i++){
        if (exist[i] == true){
            cout << bookList[i] << endl;
        }
    }
}
void allBook(vector <string> &bookList, vector <bool> &exist){
    for(int i = 0; i < bookList.size(); i++){
        cout << bookList[i] << endl;
    }
}
void takeBook(vector <string> &bookList, vector <bool> &exist){
    int n;
    cout << "Введіть номер книги яку ви хочете взяти ";
    cin >> n;
    if (exist[n - 1] == true){
        exist[n - 1] = false;
        cout << "Книга успішно взята!" << endl;
    }
    else{
        cout << "Нажаль цієї книги нема в наяності(" << endl;
    }
}
void bookReturn(vector <string> &bookList, vector <bool> &exist){
    int n;
    cout << "Введіть номер книги яку ви хочете повернути ";
    cin >> n;
    if (exist[n - 1] == false){
        exist[n - 1] = true;
        cout << "Книга успішно повернута!" << endl;
    }
    else{
        cout << "Нажаль у вас не має цієі книги(" << endl;
    }
}
int main(){
    int n;
    bool cont = true;
    vector <string> bookList = {"book1", "book2", "book3", "book4", "book5", "book6"};
    vector <bool> exist = {true, true, true, true, true, true};
    do{
        menu:
        cout << "Виберіть опцію з інуючих:" << endl;
        cout << "1 - перелчити всі книги" << endl;
        cout << "2 - перелічити наявні книги" << endl;
        cout << "3 - повернути книгу" << endl;
        cout << "4 - взяти книгу" << endl;
        cout << "5 - закінчити роботу" << endl;
        cin >> n;
        switch (n){
        case 1:
            allBook(bookList, exist);
            break;
        case 2:
            enumerate(bookList, exist);
            break;
        case 3:
            bookReturn(bookList, exist);
            break;
        case 4:
            takeBook( bookList, exist);
            break;
        case 5:
            cont = false;
            break;
        
        default:
            cout << "Виберіть опцію з наявних!" << endl;
            goto menu;
            break;
        }
    }while(cont);
    return 0;
}