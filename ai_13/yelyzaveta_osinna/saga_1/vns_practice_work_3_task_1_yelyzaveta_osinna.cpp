#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double S;
    cout << "Введіть довжину дистанції (метрів) > ";
    cin >> S;

    int minutes;
    int seconds;
    cout << "Введіть час (хвилин.секунд) > ";
    char dot;
    cin >> minutes >> dot >> seconds;

    double t = minutes*60 + seconds;

    double v_ms = S/t;
    double v = v_ms*3.6;


    cout << "Дистанція: " << S << " м" << endl;
    cout << "Час " << minutes << " хв " << seconds << " сек = " << t << " сек" << endl;
    cout << "Швидкості бігу = " << fixed << setprecision(2) << v << " км/година" << endl;

    return 0;
}