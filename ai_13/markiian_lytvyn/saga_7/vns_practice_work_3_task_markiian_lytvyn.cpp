#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int distance, minutes, seconds;
    cout << "Введіть довжину дистанції (метрів): " << endl;
    cin >> distance;
    cout << "Ведіть час (в хвилинах та секундах)" << endl;
    cin >> minutes >> seconds;


    double s = (distance/1000) /((minutes * 60 + seconds)/ 3600);


    cout << "Дистанція: " << distance << " м\n";
    cout << "Час: " << minutes << " Хвилин та " << seconds << " Секунд" << endl;
    cout << "Швидкість: " << s << " км/годину\n";
}