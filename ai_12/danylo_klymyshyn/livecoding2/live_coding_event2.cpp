#include <iostream>
#include <cstring>
#include <cmath>

void createFile(char name[10], double distance, char system[10]){
    double distance_mile, distance_km, distance_usmile;

    double price_per_meter = 0.0005;
    double price_per_mile = 0.8;
    double price_per_usmile = 1.2;


    int i = 0, userid = 0;
    while(name[i] != '\n' || name[i] != '\0'){
        userid += static_cast<int>(name[i]) * pow(10, i);
        ++i;
    }
    userid = userid / 0.4;

    if(strcmp(system, "meter") == 0){
        distance_km = distance;
        distance_mile = 1609.344 * distance;
        distance_usmile = 1609.347 * distance;
    }
    else if(strcmp(system, "mile") == 0){
        distance_km = distance / 1609.347;
        distance_mile = (distance * 1609.344)/ 1609.347 ;
        distance_usmile = distance;
    }
    else if(strcmp(system, "mile_us") == 0){
        distance_km = distance / 1609.344;
        distance_mile = distance;
        distance_usmile = (distance * 1609.347) / 1609.344;
    }

    double totalPrice;  
    FILE *file_distance = fopen("data.txt", "r");

    if(!file_distance){
        std::cout << "No data found.";
        FILE *file_distance = fopen("data.txt", "w");
        fprintf(file_distance, "%d", userid);
        fprintf(file_distance, "%lf", distance_km);
        fprintf(file_distance, "%lf", distance_mile);
        fprintf(file_distance, "%lf", distance_usmile);

        totalPrice = distance_km * price_per_meter;

        std::cout << "Your discount: " << "0 $" << std::endl;
        std::cout << "Saved distance: 0 km" << std::endl;
        std::cout << "Price: " << totalPrice << "$" << std::endl;

    }
    else{

        int scanned_user_id;
        double scanned_distance_km, scanned_distance_mile, scanned_distance_usmile;
        fscanf(file_distance, "%1d", &scanned_user_id);

        fscanf(file_distance, "%1lf", &scanned_distance_km);
        fscanf(file_distance, "%1lf", &scanned_distance_mile);
        fscanf(file_distance, "%1lf", &scanned_distance_usmile);

        if(userid == scanned_user_id){
            int deliveryDistanceInKiloMeters = scanned_distance_km;
            std::cout << "Saved distance: " << deliveryDistanceInKiloMeters;
            int discount = deliveryDistanceInKiloMeters / 100;
            std::cout << "Your discount: " << discount;
            totalPrice = distance_km * price_per_meter - discount;
        }
        else{
            std::cout << "No data found.";
            FILE *file_distance = fopen("data.txt", "w");
            fprintf(file_distance, "%d", userid);
            fprintf(file_distance, "%lf", distance_km);
            fprintf(file_distance, "%lf", distance_mile);
            fprintf(file_distance, "%lf", distance_usmile);

            totalPrice = distance_km * price_per_meter;

            std::cout << "Your discount: 0 $" << std::endl;
            std::cout << "Saved distance: 0 km" << std::endl;
            std::cout << "Price: " << totalPrice << "$" << std::endl;

        }
    }


}



int main(){

double distance;

char name[10], system[10];


std::cout << "Enter your name: ";
fgets(name, 15, stdin);

std::cout << "Enter your distance: ";
std::cin >> distance;

std::cin.ignore();
std::cout << "Enter your system: ";
fgets(system, 10, stdin);

createFile(name, distance, system);


    return 0;
}