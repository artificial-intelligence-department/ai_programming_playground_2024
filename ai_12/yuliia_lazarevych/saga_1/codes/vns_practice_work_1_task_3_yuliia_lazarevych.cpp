//Обчислення величини доходу по внеску.
//Процентна ставка (% річних) і час зберігання (днів) задаються під час роботи програми.

#include <iostream>
#include <cmath>

using namespace std;

double calculateDohid(int vnesok, double stavka, double termin) {//функція для обчислення доходу
    return vnesok * (stavka/100.0) * (termin / 365.0);//мат. операції для обчислення доходу
}

int main(){
    char repeat;
    do{//цикл `do while` для повторення розрахунків за бажанням юзера
        int vnesok, termin, stavka;
        double sum;
        cout << "Обчислення величини доходу по внеску.\n" << "Введіть початкові дані:\n" << "Величина внеску (грн.) " << endl;
        cin >> vnesok;
        cout << "Термін внеску (днів) " << endl;
        cin >> termin;
        cout << "Процентна ставка (річних в %) " << endl;
        cin >> stavka;

        double dohid=calculateDohid(vnesok, stavka, termin);
        sum = vnesok + dohid;
        cout << "Дохід: " << dohid << endl << "Сума, після закінчення терміну внеску: " << sum << endl;
        cout << "Бажаєте виконати ще один розрахунок?(y/n): ";
        cin >> repeat;
    } while (repeat == 'y' or repeat == 'Y');
    return 0;
}
