#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void print(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    int n;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    const int N = 100;
    int arr[N];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Початковий масив: ";
    print(arr, n);
    // Знищити елемент із номером К.
    int K;
    cout << "Введіть номер елемента для видалення (пояинаючи з 1): ";
    cin >> K;
    
    if (K >= 1 && K <= n) {
        for (int i = (K-1); i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; 
    } else {
        cout << "Неправильний номер елемента" << endl;
    }

    cout << "Масив після видалення елемента: ";
    print(arr, n);

    //  Додати після кожного парного елемента масиву елемент зі значенням 0.
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            
            if (n + 1 >= N) {
                cout << "Масив заповнений" << endl;
                break;
            }

            for (int j = n; j > i; j--) {
                arr[j] = arr[j - 1];
            }

            arr[i + 1] = 0;
            n++; 
            i++; 
        }
    }

    cout << "Масив після додавання 0 після кожного парного елемента: ";
    print(arr, n);

    return 0;
}
