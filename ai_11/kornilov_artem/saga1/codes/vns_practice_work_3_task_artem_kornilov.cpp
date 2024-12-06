#include <iostream>
#include <cmath>

#define Pi 3,14

using namespace std;

int main () {
    double speed;
    int distance;
    double time;

    cout << "Enter the distance (m):" << endl;
    cin >> distance;
    cout << "Enter the time (minutes.seconds):" << endl;
    cin >> time;

    int temp = time;
    double timeS = temp*60 + (time - temp)*100;
    speed = distance/timeS*3600/1000;
    cout << "The speed is " << speed << "km/h\n";

    cout << "-----------------------PASHALKO------------------------\n";
    cout << "Secret functionality:\n";
    cout << "Enter the sphere radius:\n"; 
    double area, volume;
    int radius;
    cin >> radius;

    area = 4*Pi*pow(radius, 2);
    volume = 3*Pi*pow(radius, 3)/4;

    cout << "The area of a sphere equals:\n" << area << endl;
    cout << "The volume of a sphere equals\n" << volume << endl;

    return 0;
}