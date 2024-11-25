#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> array(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    int droneL = 0;
    int droneR = N - 1;

    while (true) {
 
        if (droneL == droneR) {
            cout << droneL + 1 << " " << droneR + 1 << endl;
            cout << "Collision" << endl;
            break;
        }
        if (droneL > droneR) {
            cout << droneL + 1 << " " << droneR + 1 << endl;
            cout << "Miss" << endl;
            break;
        }
        if (droneL + 1 == droneR) {
            cout << droneL + 1 << " " << droneR + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        droneL += array[droneL];
        droneR -= array[droneR];
    }

    return 0;
}
