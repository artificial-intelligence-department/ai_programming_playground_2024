#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distance, minutes, seconds, time, speed;

    cout << "Enter the length of the distance (meters) > ";
    cin >> distance;
    cout << "Enter the time (minutes.seconds) > ";
    cin >> minutes;

    seconds = (minutes - int(minutes)) * 60;
    time = int(minutes) * 60 + seconds;
    speed = (distance / 1000) / (time / 3600);

    cout << "Distance: " << fixed << setprecision(0) << distance << " m" << endl;
    cout << "Time: " << int(minutes) << " min " << int(seconds) << " sec = " << fixed << setprecision(0) << time << " sec" << endl;
    cout << "Running speed = " << fixed << setprecision(2) << speed << " km/hour" << endl;

    return 0;
}
