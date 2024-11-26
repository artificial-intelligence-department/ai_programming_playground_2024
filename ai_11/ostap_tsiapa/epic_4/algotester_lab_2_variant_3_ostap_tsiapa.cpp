#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Введіть розмір масиву: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int leftDrone = 0;
    int rightDrone = N - 1;

    while (true) {
        if (leftDrone == rightDrone) {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Collision" << endl;
            break;
        }
        if (leftDrone + 1 == rightDrone) {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        if (leftDrone > rightDrone) {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Miss" << endl;
            break;
        }

        leftDrone += arr[leftDrone];
        rightDrone -= arr[rightDrone];
    }

    return 0;
}
