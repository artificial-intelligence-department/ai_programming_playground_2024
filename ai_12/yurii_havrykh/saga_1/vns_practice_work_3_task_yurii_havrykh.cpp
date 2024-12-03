#include<bits/stdc++.h>

using namespace std;

int main() {
    int dist;
    float petrol, cost_petrol;
    cout << "Введіть початкові дані:" << endl;
    cout << "Відстань до дачі (км) > ";
    cin >> dist;
    cout << "Витрата бензину (літрів на 100 км пробігу) > ";
    cin >> petrol;
    cout << "Ціна літра бензину (грн.) > ";
    cin >> cost_petrol;
    float trail_cost = float(dist * 2) / 100 * cost_petrol * petrol;
    printf("Поїздка на дачу і назад обійдеться в %.2f грн.\n" ,trail_cost);
}