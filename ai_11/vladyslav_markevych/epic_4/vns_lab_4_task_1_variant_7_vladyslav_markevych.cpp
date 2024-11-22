#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(time(0)); 
    vector<int> array;
    int n = 10; 
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 11); 
    }

    cout << "Початковий масив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    for (int i = array.size() - 1; i >= 0; i--) {
        if (array[i] == 0) {
            array.erase(array.begin() + i);
            break;
        }
    }

    cout << "Після видалення останнього 0: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    int index;
    cout << "Введіть індекс для додавання елемента після: ";
    cin >> index;

    if (index >= 0 && index < array.size()) {
        array.insert(array.begin() + index + 1, 100);
    } else {
        cout << "Неправильний індекс!" << endl;
    }

    cout << "Остаточний масив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
