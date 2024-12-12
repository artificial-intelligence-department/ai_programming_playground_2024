/**
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
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

class Delivery {
    private:
    static constexpr double mile = 1609.344;
    static constexpr double mile_us = 1609.347;

    double pricemeter, pricemile, pricemileus;
    double bonusdistance;
    int userid = 0;
    std::string user;

    bool ispalindrome(int distance){

    }

    void sortname(char* name, int length){
        for(int i = 0; i < length - 1; i++){
            for(int j = 0; j < length - i - 1; j++){
                if(name[j] > name[j+1]){
                    char temp = name[j];
                    name[j] = name[j+1];
                    name[j+1] = temp;
                }
            }
        }
    }

    double convertation(double distance, const std::string& type) {
        if(type == "mile"){
            return distance * mile;
        } else if(type == "mile_us"){
            return distance * mile_us
        }
        return distance;
    }


    void prices(){
    std::ifstream meterpricefile("price_per_meter.txt");
    std::ifstream milepricefile("price_per_mile.txt");
    std::ifstream mileuspricefile("price_per_mile_us.txt");

    if(!meterpricefile.is_open() || !milepricefile.is_open() || !mileuspricefile.is_open()){
        std::cerr << "Неможливо відкрити файли";
        exit(1);
    }
    // double pricemeter, pricemile, pricemileus;
    meterpricefile >> pricemeter;
    milepricefile >> pricemile;
    mileuspricefile >> pricemileus;

    meterpricefile.close();
    milepricefile.close();
    mileuspricefile.close();
    }

    void readcollecteddistance(const std::string& username){
    std::string filename = "collected_distance.txt";
    std::ofstream file(filename);
        if(file.is_open()){
            std::string userinfile;
            double distance;
            file >> userinfile >> distance;
            file.close();
            if(userinfile == username){
                return distance;
            }
        }
    }

    void savecollecteddistance(){
        std::string filename = "collected_distance.txt";
        std::ifstream file(filename);
        if (file.is_open()) {
            file << asciiusername << " " <<
            file.close();
        }
    }

    public:
    delivery(){
        loadprices();
    }

    void checkname(const std::string& name){
        char sortname[100];
        int length = name.length();
        for(int i = 0; i < length; i++){
            sortname[i] = name[i];
        }

    sortname(sortname, length);

    std::stringstream ss;
    for(int i = 0; i < length; i++){
        if(i > 0) ss << " ";
        ss << static_cast<int>(sortname[i]);
    }
    asciiusername = ss.str();
    calcdistance = readcollecteddistance(asciiusername);
    }


    double calculateprice(double distance, const std::string& type){

    }

};






int main(){
    Delivery delivery;
    std::string username;
}