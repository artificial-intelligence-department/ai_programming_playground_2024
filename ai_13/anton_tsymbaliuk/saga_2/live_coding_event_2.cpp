#include <iostream>
#include <fstream>
#include <sstream>

bool isPalindrome(double distance){
    std::ostringstream strs;
    strs << distance;
    std::string str = strs.str();
    int i, j;
    i = 0;
    j = str.size() - 1;
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}


int main(){
    std::fstream fMile("mile.txt", std::ofstream::out | std::ofstream::in);
    fMile << 0.8;
    std::fstream fUS_Mile("us_mile.txt", std::ofstream::out | std::ofstream::in );
    fUS_Mile << 1.2;
    std::fstream fMetr("mext.txt", std::ofstream::out | std::ofstream::in);
    fMetr << 0.0005;
    fMile.seekp(0);
    fUS_Mile.seekp(0);
    fMetr.seekp(0);
    
    std::string username;
    std::cout << "Enter username : ";
    std::cin >> username;
    std::cout << "Enter distance : ";
    double distance;
    std::cin >> distance;
    std::cout << "Enter unit of measurment(meter/mile/mile_us) : ";
    std::string measurmentSystem;
    std::cin >> measurmentSystem;
    std::string IDstring = username;
    bool sorted = false;
    do{
        sorted = true;
        for(int i = 0; i < IDstring.size() - 1; i++) if(IDstring[i] > IDstring[i+1]){
            sorted = false;
            std::swap(IDstring[i], IDstring[i + 1]);
        }

    }while(!sorted);


    int IDarr[sizeof(IDstring)];
    for(int i = 0; i < IDstring.size(); i++) IDarr[i] = IDstring[i] * 0.4;

    
    std::string convertStr;
    std::cout << "Do you want to convert your bonuses(y/n) : ";
    std::cin >> convertStr;
    bool convert = convertStr == "y" ? 1 : 0;
    double distanceInMeters;
    double price;
    double pricePerMeasure;
    if(measurmentSystem == "meter"){
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
    std::fstream collectedDistance("collectedDistance.txt",  std::ofstream::out | std::ofstream::in);
    collectedDistance.seekp(0);
    if(convert){
        
    }



    fMile.close();
    fUS_Mile.close();
    fMetr.close();
    return 0;
}