#include <iostream>
#include <iomanip>   
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const double MILE_TO_METER = 1609.344; 
const double US_MILE_TO_METER = 1609.347;
const string FILENAME_RESULT = "collected_distance.txt";

bool isPalindrome (int distance){
  string distStr  = to_string(distance);
  string reverseStr = string(distStr.rbegin(), distStr.rend());
  return distStr  == reverseStr;
}

int convertToMeters(double distance , string unit){
  if (unit == "meter") //в коді використані умовні оператори та розгалуження
  {
    return static_cast<int>(distance);
  }
  else if (unit == "mi")
  {
    return static_cast<int>(distance * MILE_TO_METER);
  }
  else if (unit == "mi_US")
  {
    return static_cast<int>(distance * US_MILE_TO_METER);
  }
  else
  {
    cout << "Invalid unit.";
    return static_cast<int>(distance);
  }
}

void createUserId(const string& name,int& userId){
  string sortedName = name;
  sort(sortedName.begin(), sortedName.end());

  userId = 0;
  for (char c : sortedName){
    userId += static_cast<int> (c) * 0.4;
  }
}

void saveToFile (const string& name,int userId,int distance){
  ofstream outFile (FILENAME_RESULT , ios::app);//в коді використано функції роботи з файлами, для того, щоб записати у файл
  if(outFile.is_open()){
    outFile << name << endl;
    outFile << userId << " " << distance << endl;
    outFile.close();
    cout << "Data saved to " << FILENAME_RESULT << endl;
  }
  else {
    cout << "Error: Unable to save data to file " << endl;
  }
}

int main (){
  string name , unit , convertBonus;
  double distanceInput; //в коді використана як мінімум одна дійсна змінна

  cout << "Enter your name: ";
  cin >> name;

  cout << "Enter distance: "; //в коді використано оператори виведення та введення даних
  cin >> distanceInput;

  cout << "Enter the unit of measurement (meter, mi, mi_US): ";
  cin >> distanceInput;

  int distance = convertToMeters(distanceInput,unit); // в коді використана як мінімум одна цілочисельна змінна
  cout << "Converted Distance: " << distance << " meters" << endl;

  int bonusDistance = isPalindrome(distance) ? 200 : 0;
  if (bonusDistance > 0) {
    cout << "Is Palindrome, +200 bonuses" << endl;
  }

  int totalDistance = distance + bonusDistance;
  cout << "Total Distance: " << totalDistance << " meters" << endl;

  cout << "Want to convert bonuses into distance? (y/n)? ";
  cin >> convertBonus;

  if(convertBonus == "y" || convertBonus == "Y"){
    totalDistance -= bonusDistance;
    cout << "Bonus converted! Remaining distance: " << totalDistance << " meters" << endl;
    bonusDistance = 0;
  }
  else {
    cout << "Bonuses not converted." << endl;
  }

  int userId;
  createUserId(name, userId);
  cout << "Generated User ID: " << userId << endl;

  saveToFile(name,userId,totalDistance);

  return 0;
}