#include <iostream>
using namespace std;

//використовую структуру для зберігання інформації про дрон
struct Drone {
    int position;
};

int main() {
    int N;
    cin >> N;

    //використовую динамічний масив для зберігання швидкостей
    int* arr = new int[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    //ініціалізую дрони
    Drone leftDrone = {1};
    Drone rightDrone = {N};

    while (true) {
        if (leftDrone.position == rightDrone.position) {
            cout << leftDrone.position << " " << rightDrone.position << endl;
            cout << "Collision" << endl;
            break;
        }
        if (leftDrone.position + 1 == rightDrone.position) {
            cout << leftDrone.position << " " << rightDrone.position << endl;
            cout << "Stopped" << endl;
            break;
        }
        if (leftDrone.position > rightDrone.position) {
            cout << leftDrone.position << " " << rightDrone.position << endl;
            cout << "Miss" << endl;
            break;
        }

        leftDrone.position += arr[leftDrone.position];
        rightDrone.position -= arr[rightDrone.position];
    }

    //звільняюю динамічну пам'ять
    delete[] arr;

    return 0;
}
