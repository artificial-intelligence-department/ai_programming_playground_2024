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
    std::string name, metr_sys;
    double dist;
    int* index = new int[0];

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
    double dist_in_km, suma, sale, nakop;
    Person first;

    std::cout << "Введіть ваше ім'я : ";
    std::cin >> first.name;
    std::cout << "Введіть відстань : ";
    std::cin >> first.dist;
    std::cout << "Введіть одиницю виміру (meter/mile/mile_us) : ";
    std::cin >> first.metr_sys;

    bubble_sort(first.name, first.index);
    // for(int i =0; i<name.size(); i++){
    //     std::cout << index[i];
    // }

    if(first.metr_sys!="meter" && first.metr_sys!="mile" && first.metr_sys!="mile_us"){
        return 0;
    }

    std::ofstream pr_met("price_per_meter.txt", std::ios::binary);
    if(pr_met.is_open()){
        pr_met << 0.0005;
    } else {
        std::cerr << "Файл не вдалося відкрити" << " price_per_meter.txt";
    }

    std::ofstream pr_mi("price_per_mile.txt", std::ios::binary);
    if(pr_mi.is_open()){
        pr_met << 0.8;
    } else {
        std::cerr << "Файл не вдалося відкрити" << " price_per_mile.txt";
    }

    std::ofstream pr_mi_us("price_per_mile_us.txt", std::ios::binary);
    if(pr_mi_us.is_open()){
        pr_met << 1.2;
    } else {
        std::cerr << "Файл не вдалося відкрити" << " price_per_mile_us.txt";
    }


    std::cout << "\n";





    std::ofstream outFile("Data.txt", std::ios::binary);
    if(outFile.is_open()){
        outFile.write(reinterpret_cast<char*>(&first), sizeof(Person));
        outFile.close();
    } else {
        std::cerr << "Файл не вдалося відкрити";
    }

    Person help;
    std::ifstream iFile("Data.txt", std::ios::binary);
    if(iFile.is_open()){
        while(iFile.read(reinterpret_cast<char*>(&help), sizeof(Person))){
            double pr;
            std::string line;
            if(first.metr_sys == "meter"){
                dist_in_km = first.dist/1000;
                std::ifstream price("price_per_meter.txt", std::ios::binary);
                if(price.is_open()){
                    std::getline(price, line);
                    pr = atoi(line.c_str());
                }
            }
            if(first.metr_sys == "mile"){
                dist_in_km = first.dist*1609.344/1000;
                std::ifstream price("price_per_mile.txt", std::ios::binary);
                if(price.is_open()){
                    std::getline(price, line);
                    pr = atoi(line.c_str());
                }
            }
            if(first.metr_sys == "mile_us"){
                dist_in_km = first.dist*1609.347/1000;
                std::ifstream price("price_per_mile_us.txt", std::ios::binary);
                if(price.is_open()){
                    std::getline(price, line);
                    pr = atoi(line.c_str());
                }
            }
            sale = std::round(dist_in_km/100);
            nakop = sale*100;
            if(is_palindrom(dist_in_km)){
                sale+=2;
                nakop +=200;
            }
            
            suma = dist_in_km*pr - sale;
        }
        outFile.close();
    } else {
        std::cerr << "Файл не вдалося відкрити" << " Data.txt";
    }

    std::cout << "\n";

    if(suma > 0){
        std::cout << "Відстань поточної доставки: " << simulateMoneyPrecision(dist_in_km*1000) << " m" << "\n";
        std::cout << "Ваша знижка: " << sale << " $" << "\n";
        std::cout << "Накопичена відстань: " << nakop << " km" << "\n";
        std::cout << "Вартість відправки: " << suma << " $" << "\n";
    } else {
        std::cout << "Відстань поточної доставки: " << simulateMoneyPrecision(dist_in_km*1000)  << " m" << "\n";
        std::cout << "Ваша знижка: " << sale << " $" << "\n";
        std::cout << "Накопичена відстань: " << nakop << " km" << "\n";
        std::cout << "Відправка безкоштовна" << "\n";
    }

    



//     std::cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
// std::cout << "Ваша знижка: " << discount << "$" << endl;
// std::cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
// std::cout << "Вартість відправки: " << totalPrice << "$" << endl;
    delete[] first.index; 
    return 0;
}