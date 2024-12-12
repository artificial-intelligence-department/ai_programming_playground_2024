#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isPalindrom(int number){
    int returned = 0, original = number, ost;
    while( number > 0){
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
    for( int i = 0; i < len; i++){
        arr[i] = static_cast<int>(sorted[i]) * 0.4;
    }
    }

double converter(int distance, const string a){
    if (a == "mi") 
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
    
    int Userid[15];

    generatorindex(userName, Userid);
    cout << "index"<< endl;
    for (int i =0; i < strlen(userName); i++ ){
        cout << Userid[i] << endl;
    }
    int distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;     
 
    string measurementSystem;
    cout << "Введіть одиницю виміру (mi/m/mi_us): ";
    cin >> measurementSystem;

    ifstream file( "collected_distance.txt");
    if (!file.is_open()){
        cerr << "Error "<< endl;
        return 1;
    }
    double totalDistance = 0.0;
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

    return 0;
}