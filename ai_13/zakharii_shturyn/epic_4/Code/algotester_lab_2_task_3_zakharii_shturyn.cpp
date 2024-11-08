#include <iostream>
#include <vector>
using namespace std;

int main() {
    short size;
    cin >> size;
    vector<short> speed(size);  //заповнення масиву
    for(int i = 0; i < size; i++) {
        cin >> speed[i];
    }
    short drone1pos = 0;    //задання початкових позицій
    short drone2pos = size - 1;
    while(true)
        if(drone1pos == drone2pos) {
            cout << drone1pos + 1 << " " << drone2pos + 1<< endl;
            cout << "Collision";
            break;
        } else if (drone1pos == drone2pos - 1) {
            cout << drone1pos + 1 << " " << drone2pos + 1<< endl;
            cout << "Stopped";
            break;
        } else if (drone1pos > drone2pos) {
            cout << drone1pos + 1 << " " << drone2pos + 1<< endl;
            cout << "Miss";
            break;
        } else {
            drone1pos += speed[drone1pos];
            drone2pos -= speed[drone2pos];
        }



    return 0;
}