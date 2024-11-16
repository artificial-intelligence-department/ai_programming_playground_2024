#include <iostream>
#include <sstream>

using namespace std;

int func(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int func(const string& str) {
    int count = 0;
    stringstream ss(str);
    string word;
    
    while (ss >> word) {
        if (word.front() == word.back()) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {-5, 3, -2, 0, -7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Кількість від'ємних елементів: " << func(arr, size) << endl;

    string text = "john level civic world";
    cout << "Кількість слів, що починаються та закінчуються на ту ж букву: " << func(text) << endl;

    return 0;
}
