#include <iostream>
#include <vector>

using namespace std;

int main(){
    int size;
    cin >> size;
    vector<int> vec(size);

    for(int i = 0; i < size; i++)cin >> vec[i];

    int leftDrone = 1;
    int rightDrone = size;
    int i = 0;
    int j = size - 1;

    while(i != j && i < j && j != i + 1){
        leftDrone += vec[i];
        i += vec[i];
        rightDrone -= vec[j];
        j -= vec[j];
    }

    if(i == j){
        cout << leftDrone << " " << rightDrone << "\nCollision";
    }

    else if(j == i + 1){
        cout << leftDrone << " " << rightDrone << "\nStopped";
    }

    else{
        cout << leftDrone << " " << rightDrone << "\nMiss";
    } 

    return 0;
}