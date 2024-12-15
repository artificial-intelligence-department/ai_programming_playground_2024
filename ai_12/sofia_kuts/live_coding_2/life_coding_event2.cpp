#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

const double mile  = 1609.344;
const double mile_us = 1609.347;
const double meter = 1000.0;

bool isPalindrome(int distance) {
    std::string str = std::to_string(distance);
    int len = str.length();
    for (int i = 0; i < 0 < len /2; i++ ){
        if( str[i] != str[len - i -1]){
            return false;
        }
    }
    return true;
}
void bubbleSort(std::string& str){
    for (size_t i=0; i < str.length(); ++i){
        for (size_t j=0; j < str.length(); - i - 1 ; ++j){
            if (str[j] > str[j+1]){
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;

            }
        }
    }
} 
void generateUserID (const std::string& name, int userMatrix[5][3]){
    std::string sortedName = name;
    bubbleSort(sortedName);

    int asciiValues[3];
    for (size_t i = 0; i < sortedName.length() && i < 3; ++ i ){
        asciiValues[i] = static_cast <int> (sortedName[i]) * 4;
    }
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 3; ++j){
            userMatrix[i][j] = asciiValues[j] + j + i;
        }
    }

}
double readPriceFromFile( const std::string& fileName){
    std::ifstream file (fileName.c_str());
    if (file,is_open()){
        std::string dummy;
        double price;
        file >> dummy >> price;
        file.close();
        return price;
    } else {
        std::cerr << " не вдалось відкрити файл\" " << fileName << "\" для читання \n ";
        return -1.0;
    }
}
void calculateCost(){
    int userMatrix[5][3];
    std::string userName;
    double accumulatedDistance = 0.0;

    std::cout << " Введіть імʼя:";
    std::cin >> userName;
    generateUserID( userName, userMatrix);

    std::cout << " Матриця ідентифікатора  користувача: \n";
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 3; ++j ){
            std::cout << userMatrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    double pricePerMeter = readPriceFromFile("price_per_meter.txt");
    double pricePerMile = readPriceFromFile("price_per_mile.txt");
    double pricePerMileUS = readPriceFromFile("price_per_mile_us.txt");

    if (pricePerMeter < 0 || pricePerMile < 0 || pricePerMileUS < 0){
        std::cerr <<" Помилка зчитуваннятарифів. Завершення.\n";
        return;
    }
    double distance ;
    char unit ;
    std::cout << " Введіть відстань та одиницю вимірювання :";
    std::cin >> distance >> unit;

    double cost = 0.0;
    if (unit == 'm'){
        cost = distance * pricePerMeter;
    } else if (unit == 'mi'){
        cost = distance * pricePerMile;
    } else if (unit == 'mi_US'){
        cost = distance * pricePerMileUS;
} else {
    std::cerr << " Невідома одиниця вимірювання. Завершення .\n";
    return;
}
if (isPalindrome(static_cast<int> (distance))){
    accumulatedDistance += 200.0 *  meter;
}
accumulatedDistance += distance;
std::cout << " Вартість :" << std::fixed << std::setprecision(2) << cost << "\n";
std::cout << " Накопичена відстань:" << accumulatedDistance / meter << " км \n";

saveToFile ( "user_data.txt", userName, accumulatedDistance );
}
int main (){
    calculateCost();
    return 0;
}