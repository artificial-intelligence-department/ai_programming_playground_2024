#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const double mi = 1609.344;
const double mi_us = 1609.347;
const int m = 1;

//ім'я
//відстань
//одиниці виміру

string sort(const string& str) {
    string newS = str;
    for(int i = str.size() - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(newS[j]>newS[j+1]) {
                char temp = newS[j];
                newS[j] = newS[j+1];
                newS[j+1] = temp;
            }
        }
    }
    return newS;
}

int findSize(int num) {
    int size = 1;
    while(num >=10) {
        num /= 10;
        size++;
    }
    return num;
}

bool isPalindrom(int num,  int endInd, int startInd=0) {
    if(num<10) ;
    if(startInd > endInd) ;
    else { 
    int start = num;
    while(start > pow(10, startInd+1)) {
        start /= 10;
    }
    while(start >= 10)
        start = start%10;
    int end = num;
    int count = 0;
    while(count < startInd+1) {
        end = end % 10;
        count++;
    }
    while(end >= 10) {
        end /= 10;
    }
    if(start != end) return false;
    return isPalindrom(num, endInd-1, startInd+1);
    }
    return true;
}

double conv(int num, string s) {
    if(s=="m") 
        return num*m;
    if(s=="mi")
        return num*mi;
    if(s=="mi_us")
        return num*mi_us;
}

double findC(string &s) {
    if(s=="m") {
        ifstream file("price_per_meter.txt");
        string buf;
        getline(file, buf);
        return stod(buf);
    } 
    if(s=="mi") {
        ifstream file("price_per_mile.txt");
        string buf;
        getline(file, buf);
        return stod(buf);}
    if(s=="mi_us") {
        ifstream file("price_per_mile_us.txt");
        string buf;
        getline(file, buf);
        return stod(buf);
    }
}

int main() {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << "Enter length: ";
    int len;
    cin >> len;
    string system;
    do {
        cout << "Enter system (mi, mi_us, m): ";
        cin >> system;
    } while(system != "mi" && system != "mi_us" && system != "m");

    string sortedName = sort(name);
    int *arr = new int[sortedName.size()];
    for(int i = 0; i < sortedName.size(); i++) {
        arr[i] = sortedName[i]*0.4;
    }
    //Отриманий масив є ідентифвікатором користувача

    double newL = conv(len, system);
    int bonuses = 0;
    if(isPalindrom(newL, findSize(len)))
        bonuses+= 200;
    bonuses += static_cast<int>(newL/100);
    //Обрахування бонусів

    char c;
    do {
        cout << "Do you want to use your bonuses? (y/n)";
        cin >> c; 
    } while(c != 'y' && c!= 'n');

    double price = len;
    if(c == 'y') {
        price -= bonuses;
    }
    double comp = findC(system);
    price *= comp;
    ofstream file("collected_distance.txt", ios::app);
    file << name << "\n";
    file << len << "\n";
    file << system << "\n\n";
    for(int i = 0; i < sortedName.size(); i++) {
        file << arr[i];
    }
    file << "\t" << price << "\n";

    //Загалом не втичг реалізувати провірку чи користувач уже не перший раз у системі,
    //ще не вчтиг форматувти запис ціни(через setpresicion(2)),
    //та загалом провірку чи сама вартість не буде від'ємною(якщо бонусів більше за неї)

    return 0;
}