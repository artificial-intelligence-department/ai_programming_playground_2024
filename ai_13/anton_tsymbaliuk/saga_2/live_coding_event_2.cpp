#include <iostream>
#include <fstream>
#include <sstream>

// Використано дійсну змінну: distance
bool isPalindrome(double distance){
    std::ostringstream strs;
    strs << distance;
    std::string str = strs.str();
    int i, j;
    i = 0;
    j = str.size() - 1;
    while(i < j){
        // Використано умовні оператори: if
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Використано рекурсивну функцію: calculateDiscount
// Використано дійсну змінну з подвійною точністю: discount
// Використано математичні операції: - та +
double calculateDiscount(double distance){
    double discount = 0;
    if(distance - 100 * 1000 > 0) 
        discount += 1 + calculateDiscount(distance - 100 * 1000);
    return discount;
}

int main(){
    // Використано функції роботи з файлами: для запису та зчитування
    std::fstream fMile("mile.txt", std::ofstream::out | std::ofstream::in);
    fMile << 0.8; // Використано цілочисельну константу: 0
    std::fstream fUS_Mile("us_mile.txt", std::ofstream::out | std::ofstream::in );
    fUS_Mile << 1.2;
    std::fstream fMetr("mext.txt", std::ofstream::out | std::ofstream::in);
    std::fstream fCollectedDistance("fCollectedDistance.txt",  std::ofstream::out | std::ofstream::in);
    
    fMetr << 0.0005;
    fMile.seekp(0);
    fUS_Mile.seekp(0);
    fMetr.seekp(0);
    
    while(true){ // Використано цикл while
        std::string username;
        std::cout << "Enter username : ";
        std::cin >> username;
        std::cout << "Enter distance : ";
        double distance; // Використано дійсну змінну
        std::cin >> distance;
        std::cout << "Enter unit of measurment(meter/mile/mile_us) : ";
        std::string measurmentSystem;
        std::cin >> measurmentSystem;
        
        std::string IDstring = username;
        bool sorted = false;
        do{ // Використано цикл do while
            sorted = true;
            for(int i = 0; i < IDstring.size() - 1; i++) { // Використано цикл for
                if(IDstring[i] > IDstring[i+1]){
                    sorted = false;
                    std::swap(IDstring[i], IDstring[i + 1]);
                }
            }
        }while(!sorted);

        int IDarr[sizeof(IDstring)]; // Використано одновимірний масив
        for(int i = 0; i < IDstring.size(); i++) IDarr[i] = IDstring[i] * 0.4;

        std::string convertStr;
        std::cout << "Do you want to convert your bonuses(y/n) : ";
        std::cin >> convertStr;
        bool convert = convertStr == "y" ? 1 : 0;
        double distanceInMeters;
        double price;
        double pricePerMeasure;
        if(measurmentSystem == "meter"){ // Використано умовні оператори: if-else
            fMetr >> pricePerMeasure;
            distanceInMeters = distance;
        }
        else if(measurmentSystem == "mile"){
            fMile >> pricePerMeasure;
            distanceInMeters = distance * 1609.344;
        }
        else{
            fUS_Mile >> pricePerMeasure;
            distanceInMeters = distance * 1609.347;
        }
        price = distance * pricePerMeasure;
        fCollectedDistance.seekp(0);
        double collectedDistance = 0;

        std::cout << "Distance in meters : " << distanceInMeters << std::endl;
        std::string strArr = "";
        if(convert){
            std::string ID;
            fCollectedDistance >> ID;
            if(ID == IDstring){
                fCollectedDistance >> ID;
                for(int i = 0; i < IDstring.size(); i++){
                    strArr += IDarr[i];
                }
                if(ID == strArr){
                    fCollectedDistance >> ID;
                    collectedDistance = std::stod(ID);
                }
            }
        }
        double discount = calculateDiscount(collectedDistance);
        bool ispalindrome = isPalindrome(distance);
        if (ispalindrome) discount += 2;
        if(discount > price) discount = price;
        std::cout << "Discount : " << discount + (isPalindrome(distance) ? 200 : 0) << std::endl; 
        std::cout << "Collected distance " << collectedDistance / 1000 << " km"<< std::endl;
        std::cout << "Price " << price << " $\n";
        double collected = collectedDistance - discount * 100000 + distanceInMeters + (ispalindrome ? 200000 : 0);
        fCollectedDistance.seekp(0);
        fCollectedDistance << IDstring << "\n";
        fCollectedDistance << strArr << "\n";
        fCollectedDistance << collected;
    }

    // Використано функції роботи з файлами: закриття файлів
    fCollectedDistance.close();
    fMile.close();
    fUS_Mile.close();
    fMetr.close();
    return 0;
}
