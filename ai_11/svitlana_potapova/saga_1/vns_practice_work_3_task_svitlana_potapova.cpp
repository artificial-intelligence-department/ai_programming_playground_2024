#include <iostream>
using namespace std;

int main(){
    int P, days;
    double percent, income, res;

    cout << "Обчислення величини доходу по внеску" << endl;
    cout <<"Введіть початкові дані:" << endl << "Величина внеску (грн): ";
    cin >> P;
   
    cout << "Термін внеску (днів): ";
    cin >> days;
  
    cout << "Процентна ставка (річних в %): ";
    cin >> percent;

    income = P * percent/100 * days/365;
    res = P + income;
  
    cout << "Дохід: " << income << endl;
    cout << "Сума, після закінчення терміну внеску: " << res << endl;

    cout << endl <<  "Обчислення об'єму порожнистого циліндра" << endl;

    float V, h, r1, r2;
    const float pi = 3.14;
    
    cout << "Введіть радіус циліндра: ";
    cin >> r1;
    cout << "Введіть радіус отвору: ";
    cin >> r2;
    cout << "Введіть висоту циліндра: ";
    cin >> h;
    
    V = pi*h*(r1*r1 - r2*r2);

    cout << "Об'єм порожнистого циліндра: " << V;

    return 0;
}