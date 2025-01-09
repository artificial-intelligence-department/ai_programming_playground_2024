#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// const для відстаней
const double METER = 1.0;
const double MI = 1609.344;
const double MI_US = 1609.347;

const double METER_PRICE = 0.0005;
const double MI_PRICE = 0.8;
const double MI_US_PRICE = 1.2;
// ідентифікатор
void userID(const string& userName);
void calculateDistance(const string& choice, double& totalDistance, double distance);
bool isPalindrome(int num);

void readFromFile(const string &filename);
void writeToFile(const string &filename, double value);


int main()
{
    const string file_meter = "price_per_meter.txt";
    const string file_mile = "price_per_mile.txt";
    const string file_mile_us = "price_per_mile_us.txt";
    const string file_RESULT = "price_per_mile_us.txt";

    writeToFile(file_meter, 0.0005);
    writeToFile(file_mile, 0.8);
    writeToFile(file_mile_us, 1.2);
    
    cout << "Enter your name: " << endl;
    string name;
    cin >> name;
    userID(name);

    double total_distance = 0.0;
    double distance;
    cout << "Enter distance: " << endl;
    cin >> distance;
    distance = distance / 1000;
    string choice;
    do
    {        
        cout << "\nEnter length measurement: \n\t1)METER;\n\t2)MI;\n\t3)MI_US.\n";
        cin >> choice;

        calculateDistance(choice, total_distance, distance);
        cout << "Total length: " << total_distance; 

        cout << "Do you want to add another measurement: (Y, N)" << endl;
        cin >> choice;
    } while(choice == "Y");

    int discount = static_cast<int>(total_distance) / 100;
    cout << "Would you like to use discount? (Y, N)" << endl;
    cin >> choice;
    if (choice == "Y")
    {
        total_distance -= discount * 100;
        cout << "After discount distance is: " << total_distance << endl;
    }
    
    writeToFile(file_RESULT, total_distance);
    readFromFile(file_RESULT);
    
    return 0;
}

void userID(const string& userName)
{   
    string name = userName;
    int size = name.length();
    int* name_array = new int[size]; 
    for (int i = 0; i < size; i++)
    {
        name_array[i] = static_cast<int>(name[i]) * 0.4;
    }   

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (name_array[j] < name_array[j-1])
            {
                swap(name_array[j], name_array[j-1]);
            }
        }
        cout << name_array[i] << " ";
    }
    delete[] name_array;
}

void calculateDistance(const string& choice, double& totalDistance, double distance)
{
    if (choice == "MI")
    {
        totalDistance += distance * MI;
    }
    else if (choice == "MI_US")
    {
        totalDistance += distance * MI_US;
    }
    else if (choice == "METER")
    {
        totalDistance += distance / 1000;
    }
    
    if (isPalindrome(static_cast<int>(totalDistance)))
    {
        totalDistance += 200.0;
    }
    
}

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return original == reversed;
}

void writeToFile(const string &filename, double value)
{
    ofstream fout(filename);
    if(!fout.is_open())
    {
        cout << "Error, can not open the file to write data!!!" << endl;
    }
    else
    {
        fout << value;
    }
}

void readFromFile(const string &filename)
{
    string str;
    ifstream fin(filename);
    if(!fin.is_open())
    {
        cout << "Error, can not open the file to write data!!!" << endl;
    }
    else
    {
        cout << "DATA FROM FILE" << endl;
        while (getline(fin, str))
        {
            cout << str;
        }
    }
}