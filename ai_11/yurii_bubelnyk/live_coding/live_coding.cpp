#include <iostream>
#include <string>
using namespace std;

// const для відстаней
const double METER = 1.0;
const double MI = 1609.344;
const double MI_US = 1609.347;
// ідентифікатор
void userID(const string& userName);
bool isPalindrome(int num);
int main()
{
    string name;
    getline(cin, name);
    cout << name;
    userID(name);

    double total_distance = 0.0;
    string choice;
    do
    {
        double distance = 0.0;
        cout << "Enter length measurement: 1)METER;\n\t2)MI;\n\t3)MI_US.\n";
        getline(cin, choice);
        cin.ignore(32767, '\n');

        cout << "Do you want to add another measurement: (Y, N)" << endl;
        getline(cin, choice);
    } while(choice == "Y");

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
}

void calculateDistance(const string& choice, double totalDistance, double distance)
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