/*
 * Ви отримали своє перше завдання на новій роботі програмістом у
 * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
 * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
 * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
 * відбувається згідно тарифікації, що зберігається у файлах.
 * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
 * - імперська (британська миля) == 1 609.344 метра; // mi
 * - миля США (US survey mile) == 1 609.347 метра; // mi_US
 * - метрична система виміру == 1 метр. // m
 *
 * Розробити програму для розрахунку вартості доставки,
 * яка буде використовувати ідентифікатор користувача та накопичувати відстані.
 * Компанія встановила наступні бонуси:
 * Якщо відстань відправлення є паліндромом, то користувач отримує +200 км бонусів.
 * Кожні накопичені 100км це 1$ знижки. Після використання накопичена відстань зменшується.
 * При обрахунку вартості запропонувати користувачу скористатись конвертацією накопичених бонусів.


 * Для формування ідентифікатора користувача використати наступний розрахунок:
    1. Відсортувати буĸви вашого імені за зростанням.
    2. Створити одновимірний масив на основі цілочисельного(int) значення
    символів (ASCII Value) помноженого на 0.4.

    Результат записати.
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>


struct Person{
    std::string name;

};


double simulateMoneyPrecision(double value) {
    return std::round(value * 100.0) / 100.0;
}

bool is_palindrom(int dist){
    int help = dist;
    int size=0;
    while (help/10 > 0){
        size++;
        help = help/10;
    }
    help = dist;
    if (help/(10*(size+1)) ==  help%10){
        help = (help - help/(10*(size-1))*10*(size-1) - help/10)/10;
        size--;
        size--;
        if(help && size>1){
            is_palindrom(help);
        }
    } else {
        return 0;
    }

    return 1;
    
}

void bubble_sort(std::string name, int* &index){
    int n = name.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (name[j] > name[j + 1]) {
                std::swap(name[j], name[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
    for(int i=0; i<n; i++){
        index[i] = name[i]*0.4;
    }
}



int main(){
    double dist, dist_in_km, nakop;
    int suma, sale;
    int* index = new int[0];
    std::string name, metr_sys;

    std::cout << "Введіть ваше ім'я : ";
    std::cin >> name;
    std::cout << "Введіть відстань : ";
    std::cin >> dist;
    std::cout << "Введіть одиницю виміру (meter/mile/mile_us) : ";
    std::cin >> metr_sys;

    bubble_sort(name, index);
    // for(int i =0; i<name.size(); i++){
    //     std::cout << index[i];
    // }

    std::ofstream outFile("Data.txt");
    if(outFile.is_open()){
        outFile << name;
    }

//     std::cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
// std::cout << "Ваша знижка: " << discount << "$" << endl;
// std::cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
// std::cout << "Вартість відправки: " << totalPrice << "$" << endl;
    return 0;
}