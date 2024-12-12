#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isPalindrom(int number){
    int returned = 0, original = number, ost;
    while( number > 0){ //цикл while для проходу по числу
        ost = number %10;
        returned = returned *10 + ost;
        number /=10;
    }
    return returned == original;
}
void generatorindex(const char* name, int arr[])
    {
        char sorted[15];
        strcpy(sorted, name);
        int len = strlen(sorted);
        for (int i = 0; i < len - 1 ; i++){
            for ( int j = 0; j < len -i -1; j++){
                if (sorted[j] > sorted[j+1]){
                    swap (sorted[j], sorted[j+1]);
                }
            }
        }
    for( int i = 0; i < len; i++){ //for цикл для руху по масиву

        arr[i] = static_cast<int>(sorted[i]) * 0.4;
    }
    }

double converter(int distance, const string a){ //параметри та аргументи функції для пеердання 
    if (a == "mi") //умовні оператори та розгалуження для вибору одиниці виміру
    return distance * 1609.344;
    if (a == "mi_US") 
    return distance * 1609.347;
    if (a == "m")
    return distance;
    else 
    return 0;
}

int main(){
    char userName[15];
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    
    int Userid[15];//одновимірний масив 


    generatorindex(userName, Userid);
    cout << "index"<< endl;
    for (int i =0; i < strlen(userName); i++ ){
        cout << Userid[i] << endl;
    }
    int distanceValue; //цілочисельна змінна для збереження відстані 
    cout << "Введіть відстань: ";
    cin >> distanceValue;     
 
    string measurementSystem;
    cout << "Введіть одиницю виміру (mi/m/mi_us): ";
    cin >> measurementSystem;

    ifstream file( "collected_distance.txt"); // в коді використано функції роботи з файлами, для того, щоб зчитати з файлу інформацію про відстань
    if (!file.is_open()){
        cerr << "Error "<< endl;
        return 1;
    }
    double totalDistance = 0.0; //дійсна з подвійною точністю змінна
    double bonusDistance = 0.0;

    while (!file.eof()){
        double distance;
        file >> distance;
        double distanceInMeters = converter(distance, measurementSystem);
        if (isPalindrom(static_cast<int>(distanceInMeters))){
            bonusDistance += (200*1000);

        }
        totalDistance += distanceInMeters;
        file.close();
    }
    
    double totalDistanceInKm = totalDistance / 1000.0;
    double sale = ( totalDistanceInKm + bonusDistance)/10000;

    cout << "Завгальна відстьань: "<< totalDistanceInKm << endl;
    cout << "Бонуси: " << bonusDistance<< endl;
    cout << "Можлива знижка: " << sale<< endl;

    char use;
    cout << "Бажаєте використати бонуси (y/n)? ";
    cin >> use;
    if (use == 'y'){
        totalDistance -= sale;
        sale = 0;
        cout << "Знижка застосована"<<endl;
    }
    else
        cout << "Знижка не застосована"<<endl;

    ifstream file_2( "price_per_meter.txt");
    if (!file_2.is_open()){
        cerr << "Error "<< endl;
        return 1;
    }
    double priceMetr;
    while (!file_2.eof()){
        file_2 >> priceMetr;
        file_2.close(); 
       
    }
    double totalPrice = totalDistance * priceMetr;
    cout << "Cума кінцева: " << totalPrice;
    return 0;
}