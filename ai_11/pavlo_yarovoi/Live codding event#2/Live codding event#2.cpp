#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(int distance) {
   string str = to_string(distance);
   string reversed_str = str;
   reverse(reversed_str.begin(), reversed_str.end())
    return str == reversed_str;
}
bool fileHere (const string& filename){
    ifstream file (filename);
    return file.good();
}
vector<int> MakeUserId(const &string name){
    string sorted_name = name;
    sort(sorted_name.begin(), sorted_name.end());
    vector<int> UserId;
    for (char c : sorted_name)
    {
        UserId.push_back(static_cast <int> (c) * 0.4);
    }
    return UserId;
}
double convertTheDistance (double distance, const string& fromUnit, const &string toUnit){
    const double Empire_to_Meters = 1609.344;
    const double US_to_Meters = 1609.347;

    if (fromUnit == "mi") distance *= Empire_to_Meters;
    else if (fromUnit == "mi_US") distance *= US_to_Meters;
    
    if (toUnit == "mi") return distance / Empire_to_Meters;
    else if (toUnit == "mi_US") distance *= US_to_Meters;

    return distance;
}
void createFile (const &string filename){
    ofstream outputFile (filename);
    if (outputFile)
    {
        outputFile << "5.0 mi_Imperial" << endl;
        outputFile << "5.0 mi_US" << endl;
        outputFile << "1200.0 m" << emdl;
        cout << "File" << filename << "File added without any slow" << endl;


    }
    else{
        cerr << "Invalid files" << filename << "!" << endl;
    }
    
}
void addAnotherDistance(const string& filename){
    ofstream outputFile(filename, ios :: app);
    if (!outputFile){
        cerr << "File unavaivable for editing" << endl;
        return;
    }

    char choice;
    do
    {
        double distance;
        string unit;

        cout << "Enter distance" << endl;
        cin >> distance;

        cout << "Enter value system(mi_Imperial, mi_US, m)" << endl;
        cin >> unit;

        outputFile << distance << "" << unit << endl;
        cout << "Data added to file" << endl;

        cout << "Do you want to enter other distance(y/n)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
}
int main (){
    const string filename = "distance.txt";
    const double price_per_meter = 0.01;

    if (!fileHere(filename)){
        cout << "File" << filename << "Havent found creating reserve file" << endl;
        createReserveFile(filename);
    }
        addAnotherDistance(filename);
        string name;
        cout << "How we should call you" << endl;

        vector <int> UserId  = MakeUserId(name);
        cout << "your ID :";
        for ( int id : userId){
            cout << id << "";
        }
        cout << endl;

        double totalDistance = 0;
        double bonusDistance = 0;
        string unit;

        ifstream inputFile(filename);
        if(!inputFile){
            cerr << "Error found" << endl;
            return 1;
        }
    
        double distance;
        while (inputFile >> distance >> unit) {
            double convertedDistance = convertTheDistance(distance, unit, "m");
            totalDistance += convertedDistance;

            if (isPalindrome(static_cast<int>(convertTheDistance(distance, unit, "m"))))
            {
                bonusDistance += 200000;
            }
            
        }
    inputFile.close();
    totalDistance += bonusDistance;
    int discount = static_cast<int>(totalDistance / 100000);
    double totalCost = totalDistance * price_per_meter;
    cout << "Keeped distance :" << totalDistance << endl;
    cout << "Bonuses :" << bonusDistance << endl;
    cout << "Discount :" << discount << endl;
    cout << "Total cost" << totalCost << "$"<< endl;

    char discountChoice;
    cout << "Would you like to use your discount bonus(y/n)" << endl;
    cin >> discountChoice;

    if (discountChoice == 'y' || discountChoice == 'Y')
    {
        totalDistance -= discount * 100000;
        totalCost = totalDistance * price_per_meter;
        cout << "Updated price now :" << totalCost << endl;
    }
    else
    {
        cout << "Regular price without discount" << endl;
    }
    
    return 0;

}