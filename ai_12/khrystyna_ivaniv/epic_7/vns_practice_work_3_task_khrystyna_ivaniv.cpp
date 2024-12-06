#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double distance, speed;
    string time;

    cout << "Обчислення швидкості бігу." << endl;
    cout << "Введіть довжину дистанції (метрів) = ";
    cin >> distance;
    cout << "Введіть час (хвилин.секунд) = ";
    cin >> time;

    size_t dot_position = time.find('.');

    int minutes = stoi(time.substr(0, dot_position));
    int seconds = stoi(time.substr(dot_position + 1));

    int total_seconds = minutes * 60 + seconds;

    double _speed = distance / total_seconds;

    float speed = _speed*3.6;

    cout << fixed << setprecision(2);
    cout << "Дистанція: " << distance << " м" << endl;
    cout << "Час " << minutes << " хв " << seconds << " сек = " << total_seconds << " сек" << endl;
    cout << "Швидкість бігу = " << speed << " км/год" << endl;

    double r, S, V;
    cout << "Введіть радіус кулі: " ;
    cin >> r;

    S = 4*M_PI*pow(r,2);
    V = (3.0/4.0)*M_PI*pow(r,3);

    cout << "S = " << S << endl;
    cout << "V = " << V << endl;

    return 0;
}
