#include <iostream>
using namespace std;

bool checkForCollision(int index1, int index2) {
    if(index1==index2)
        return true;
    return false;
}

bool checkForMissed(int index1, int index2) {
    if(index2<index1)
        return true;
    return false;
}

bool checkForStopped(int index1, int index2) {
    if(index1 + 1 ==index2) 
        return true;
    return false;
}

int main() {
    int N;
    cin >> N;
    int a[N];
    int leftIndex = 0, rightIndex = N -1;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++) {
        if(checkForCollision(leftIndex, rightIndex)) {
            cout << leftIndex + 1 << " " << rightIndex + 1 << "\n";
            cout << "Collision";
            return 0;
        }
        if(checkForMissed(leftIndex, rightIndex)) {
            cout << leftIndex + 1 << " " << rightIndex + 1 << "\n";
            cout << "Miss";
            return 0;
        }
        if(checkForStopped(leftIndex, rightIndex)) {
            cout << leftIndex + 1 << " " << rightIndex + 1 << "\n";
            cout << "Stopped";
            return 0;
        }
        int leftSpeed = a[leftIndex], rightSpeed = a[rightIndex];
        leftIndex += leftSpeed;
        rightIndex -= rightSpeed;
    }
}