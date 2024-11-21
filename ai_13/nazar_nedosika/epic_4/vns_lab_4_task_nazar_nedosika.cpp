#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cout << "Введіть кількість елементів масиву(5 - 20): ";
    cin >> size;

    srand(time(0));
    vector<int> array(size);
    
    for (int &num : array) {
        num = rand() % 100 + 1;
    }

    cout << "Оригінальний масив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    reverse(array.begin(), array.end());
    
    if (array.size() % 2 != 0) {
        array.erase(array.begin() + array.size() / 2);
    }

    vector<int> M;
    for (int i = 0; i < array.size(); ++i) {
        M.push_back(array[i] + 10);
    }
    
    for (int i = 0; i < 3; ++i) {
        array.insert(array.begin(), M[i] - 2);
    }

    cout << "Модифікований масив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
