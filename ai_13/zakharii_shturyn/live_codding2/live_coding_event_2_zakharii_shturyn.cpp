#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string filename = "collected_distance.txt";
double meter_price = 0.0005;
double mile_price = 0.8;
double us_mile_price = 1.2;

struct Person
{
    string index;
    int bonusDistance = 0;;
    int bonus = 0;
};

void showInfo(int distance, int bonusDistance, int bonus) {
    cout << "Your current delivery is " << distance << " meters" << endl;
    printf("Your current delivery is %0.2f kilometers\n", (double)bonusDistance/1000);
    cout << "You have " << bonusDistance << " bonus meters" << endl;
    cout << "You have " << bonus << "$ bonuses" << endl;
}

bool IsPalindrome(const string& line, int start, int end) {
    bool tmp = 1;
    if(start < end) {
        if(line[start] == line[end]) {
            tmp = IsPalindrome(line,start + 1, end - 1);
        } else {
            tmp = false;
        }
    }
    return tmp;
}

bool IsPalindrome(int& test_int) {
    bool tmp = 1;
    string test = to_string(test_int);
    tmp = IsPalindrome(test, 0, test.length() - 1);

    return tmp;
}

int mile_us_to_meter(int distance) {
    return distance * 1609.347;
}

int mile_to_meter(int distance) {
    return distance * 1609.344;
}

void checkUser(string& index, int distance) {
    ifstream myFile(filename, ios::in);
    ofstream tmpFile("tmp.txt", ios::app);
    bool userExist = false;
    if (myFile.is_open() && tmpFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Person newPerson;
            istringstream lineStream(line);
            lineStream >> newPerson.index >> newPerson.bonusDistance >> newPerson.bonus;
            if(newPerson.index == index) {
                userExist = true;
                newPerson.bonusDistance += distance;
                if(IsPalindrome(newPerson.bonusDistance)) {
                    newPerson.bonusDistance += 200000;
                }
                newPerson.bonus = newPerson.bonusDistance/100000;
            }
            showInfo(distance, newPerson.bonusDistance, newPerson.bonus);
            tmpFile << newPerson.index << " " << newPerson.bonusDistance << " " << newPerson.bonus << endl;
        }

        if(!userExist) {
            Person newPerson;
            newPerson.index = index;
            newPerson.bonusDistance += distance;
            if(IsPalindrome(newPerson.bonusDistance)) {
                newPerson.bonusDistance += 200000;
            }
            newPerson.bonus = newPerson.bonusDistance/100000;
            showInfo(distance, newPerson.bonusDistance, newPerson.bonus);
            tmpFile << newPerson.index << " " << newPerson.bonusDistance << " " << newPerson.bonus << endl;
        }
    }
    myFile.close();
    tmpFile.close();

    remove(filename.c_str());
    rename("tmp.txt", filename.c_str());
}

void generateuser(string& name, int distance) {
    double arrname[30];
        string index = "";
        for(int i = 0;i < name.length(); i++) {
            arrname[i] = name[i];
        }

        for(int i = 0;i < name.length(); i++) {
            arrname[i] = arrname[i] * 0.4;
            index += to_string((int)arrname[i]);
        }
    
    checkUser(index,distance);
}


int main() {

    int opt;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Which metric system do you prefer to use?\n1)Meter\n2)Mile\n3)Mile us" << endl;
    cin >> opt;

    double price = 0;

    if(opt == 1) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        price = distance * meter_price;
        generateuser(name,distance);

    } else if(opt == 2) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        price = distance * mile_price;
        distance = mile_to_meter(distance);
        generateuser(name,distance);

    } else if(opt == 3) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        price = distance * us_mile_price;
        distance = mile_us_to_meter(distance);
        generateuser(name,distance);

    }else {
        cout << "Invalid option!" << endl;
        return 0;
    }

    printf("\nYou need to pay: %0.2f$", price);

    return 0;
}