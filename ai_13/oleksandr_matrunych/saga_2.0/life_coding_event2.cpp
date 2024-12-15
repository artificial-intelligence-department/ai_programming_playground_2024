#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>


using namespace std;
//Поліндром 
bool isAPolindrom (int distance) {
    string str = to_string(distance);
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return str ==  reversedStr;
}
//Конвертація у метри
double convertToMeters (double distance, string unit){
    if(unit == "mi"){
    return distance * 1609.344;
    } 
    else if(unit == "mi_US"){
    return distance * 1609.347;
    }
    else if(unit == "m"){
    return distance * 1;
    }
    else{
        cout << "Unknown unit" << endl;
    }
}
// Формування ідентифікатора користувача
void calculateUserId(string name, int result[5][3]){
    sort(name.begin(), name.end());

    int ASCIIarray[3];
    for(int i = 0; 1 < min(size_t)3, name.size(()); i++){
    int ASCIIarray[i] = static_cast<int>(name[i]) * 0.4;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            if (j < 3){
                result [i][j] = ASCIIarray[j];
            }
            else{
                result [i][j] = static_cast<double>(i + j) / 10;

            }
        }
    }
}


int main(){
    ofstream resultFile("result.txt");
    if (!resultFile.is_open()) {
        cerr << "Error: Could not open file" << "\n";
        return 1;
    }
    string userName;
    cout << "Enter userName"; 
    cin >> userName;

    int UserIdMatrix[5][3];
    calculateUserId(userName, UserIdMatrix);

    resultFile << "User Id Matrix" << endl;
    cout << "User Id Matrix" << endl;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            resultFile << UserIdMatrix[i][j] << " ";
            cout << UserIdMatrix[i][j] << " ";
        }
    resultFile << endl;
   }

    double totalDistance = 0.0;
    int bonuses = 0;

        while(true){
            cout << "Enter distance or -1 to quit";
            double distance;
            cin >> distance;

            if (distance == -1){
                break;
            }
            cout << "Enter unit (mi, mi_US, m)";
            string unit; 
            cin >> unit;

            distance = convertToMeters(distance, unit);
            resultFile << "Distance in meters" << distance << endl;
            cout << "Distance in meters: " << distance << endl;
       
            if (isAPolindrom(static_cast<int>(distance))){
            bonuses += 200;
            resultFile << "Polindrom bonus + 200 " << endl;
            cout << "Polindrom bonus + 200 " << endl;
            }


            totalDistance += distance;
            resultFile << "total distance: " << totalDistance / 1000.0 << "km" << endl;
            resultFile << "Bonuses:" << bonuses / 100.0 << "$" << endl;
            cout << "total distance: " << totalDistance / 1000.0 << "km" << endl;
            cout << "Bonuses:" << bonuses / 100.0 << "$" << endl;
       
       
            // Використання бонусів
            char usedbonuses;
            cout << "Would you like to use your bonuses?";
       }
}