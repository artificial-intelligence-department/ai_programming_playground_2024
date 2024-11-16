/*
1.  Обчислити значення виразу при різних  дійсних типах даних (float й double). 
Обчислення  варто  виконувати  з  використанням  проміжних  змінних. Порівняти й 
пояснити отримані результати. ( (a+b)^2 - (a^2 + 2ab) )/b^2 
*/

#include "iostream"
#include "cmath"
using namespace std;

int main(){
    float af, bf, act1, act2, act3, act4;
    af = 1000;
    bf = 0.0001;

    act1 = pow((af+bf), 2); // (a+b)^2
    act2 = pow(af,2) + 2*af*bf; // (a^2 + 2ab)
    act3 = pow(bf,2); //b^2
    act4 = (act1 - act2) / act3; // ( (a+b)^2 - (a^2 + 2ab) )/b^2
    cout << "Float: " << act3<< endl;


    double ad, bd, first, second, third, forth;
    ad = 1000;
    bd = 0.0001;
    first = pow((ad+bd), 2); // (a+b)^2
    second = pow(ad,2) + 2*ad*bd; // (a^2 + 2ab)
    third = pow(bd,2); //b^2
    forth = (first - second)/third; // ( (a+b)^2 - (a^2 + 2ab) )/b^2
    cout << "Double: " << forth << endl;

    return 0;
}
