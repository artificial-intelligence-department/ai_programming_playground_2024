#include <iostream>
#include <fstream>
#include <algorithm>





// * Ви отримали своє перше завдання на новій роботі програмістом у
//  * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
//  * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
//  * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
//  * відбувається згідно тарифікації, що зберігається у файлах.
//  * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
//  * - імперська (британська миля) == 1 609.344 метра; // mi
//  * - миля США (US survey mile) == 1 609.347 метра; // mi_US
//  * - метрична система виміру == 1 метр. // m
//  *


//  * Для формування ідентифікатора користувача використати наступний розрахунок:
//     1. Відсортувати буĸви вашого імені за зростанням.
//     2. Створити одновимірний масив на основі цілочисельного(int) значення
//     символів (ASCII Value) помноженого на 0.4.


//     3. У попередньому масиві залишити лише елементи з індеĸсами від 1 до 3.
//     Створити двовимірний масив 5х3 на основі цілочисельного(int) значення
//     символів (ASCII Value) отриманих у попередньому завданні,
//     а решта значень заповнюються дійсними числами(float).
//     Перемножити ці дві матриці.
//     Результат записати.
//  */





bool is_palindrom(int tempDist){
    int temp2 = tempDist;
    int rec_num =0;
    while(temp2>0){
        rec_num= rec_num* 10 + temp2%10;
        temp2 = temp2/10;
    }

    return rec_num == tempDist;
   
} 

int main(){
    std::string userNAme;
    double dintanceVAlue;
    std::string measurementSystem;
    double bonuses;


    std::cout << "Введіть ім'я користувача: " << std::endl;
    std::cin >> userNAme;

    std::cout << "Введіть відстань(в метрах ): " << std::endl;
    std::cin >> dintanceVAlue;

    std::cout << "Введіть одиницю виміру:\n 1 mi британська\n 2 mi_US американська\n 3 m метрична " << std::endl;
    std::cin >> measurementSystem;

    double temp = 1609.344;

    if (measurementSystem == "mi") {
        dintanceVAlue *= 1609.344;
    }  else if(measurementSystem == "mi_US") {
        dintanceVAlue *=  1609.347;
    }  else if(measurementSystem == "m") {
        dintanceVAlue *= 1;
    }  

    if(is_palindrom(dintanceVAlue)) {
        dintanceVAlue += 200000;
    } 
    std::string bonusTemp;
    std::cout << "Обрахувати бонуси:\n якщо так введіть y\n якщо ні введіть n \n " << std::endl;
    std::cin >> bonusTemp;
    if(bonusTemp == "y") {
       bonuses +=  dintanceVAlue % 100;
       std::cout << bonuses;
    } else {
        
    } 




    return 0;
}