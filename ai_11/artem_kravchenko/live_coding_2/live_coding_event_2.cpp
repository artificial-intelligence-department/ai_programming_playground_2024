#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isPolindrom(int distance){
    string numberStr = to_string(distance);
    return audit(numberStr, 0, numberStr.size() - 1);
}

void output (string user_name, int distance, int bonus){
    ifstream file("collected_distance.txt");
    if (!file.is_open())
    {
        cerr << "Файл не вдалось відкрити" << endl;
        return;
    }

    string line;
    getline(file, line);

}

bool isUser(string user_name){
    ifstream file("collected_distance.txt");
    if (!file.is_open())
    {
        cerr << "Файл не вдалось відкрити" << endl;
        return;
    }
    string line;
    getline(file, line);
    if (line != user_name)
    {
        return false;
    }

    return true;
    
}

void input(string user_name, int distance, int bonus){
    ofstream file("collected_distance.txt");
    if (!file.is_open())
    {
        cerr << "Файл не вдалось відкрити" << endl;
        return;
    }
    if (!isUser)
    {
        file << user_name << endl;
        file << distance << endl;
        file << bonus << endl;
    }

    ifstream fin("collected_distance.txt");
    
    
    
}

int main(){
    string user_name;
    string system;
    string choice;
    int bonus;
    cout << "Введіть ім'я: "<< endl;
    cin >> user_name;
    int distance;
    cout << "Введіть відстань: " << endl;
    cin >> distance;
    if (isPolindrom)
    {
        bonus += 200;
    }
    
    cout << "Введіть одиницю виміру: "<< endl;
    cin >> system;

    

    return 0;
}