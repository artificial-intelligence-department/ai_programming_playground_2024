#include <iostream>
#include <ctime>

using namespace std;

int main(){
int menu,player,bot;
cout << "Вас вітає гра Сапер" << endl << "[1] Розпочати гру" << endl << "[2] Вийти" << endl;
cin >> menu;
if (menu>0 && menu < 3){
    if (menu == 1){
        srand(time(NULL));
        bot = 1 + rand() % 3;
        cout << "Бомба замінована, оберіть колір провода який хочете обрізати: " << endl;
        cout << "[1] Синій" << endl << "[2] Червоний" << endl << "[3] Жовтий" << endl << "[4] Зелений" << endl;
        cout << "Введіть число від 1 до 4: ";
        cin >> player;
        if (player >0 && player <5){
            if ( player == bot ){
                cout << "Вітаю! Ви перемогли, обравши вірний провід!" << endl;
                cout << "Ви обрали: " << player << " Правильний провід: " << bot << endl;
            }
            else {
                cout << "Ви програли! Але наступного разу точно вдасться!" << endl;
                cout << "Ви обрали: " << player << " Правильний провід: " << bot << endl;
            }
        }
        else{
                cout << "Ви ввели неправильне значення!";
                return 0;
            }
    }
    else if (menu == 2) {return 0;}
}
else{
    cout << "Ви ввели неправильне значення!";
    return 0;
}
}