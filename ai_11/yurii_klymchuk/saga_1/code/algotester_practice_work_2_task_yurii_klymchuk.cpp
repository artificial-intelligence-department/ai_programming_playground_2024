#include <iostream>

using namespace std;

//використав цілочисельну змінну, ввід/вивід, динамічний масив,
//цикл фор, функцію, цикл do while, оператори розгалуження,
//break 

void Collision(int right, int left, int* arr) { 
    do {
        if (left == right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Collision\n";
            break;
        }
        else if (left + 1 == right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Stopped\n";
            break;
        }
        else if (left > right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Miss\n";
            break;
        }
        left += arr[left];    
        right -= arr[right];   
    } while(true);
    
    delete[] arr;
}
int main() {
    int N;
    cin >> N;
    
    int* arr = new int [N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;

    Collision(right, left, arr);
    return 0;
}