#include <iostream>
#include <cmath>
using namespace std;

bool checkWin(long long* arr, int count, int size) {
    if (count == size) {
        return true;
    }
    if (arr[count] <= 0) {
        cout << "ERROR";
        return false;
    }
    if (count != 0 && arr[count] > arr[count - 1]) {
        cout << "LOSS";
        return false;
    }
    return checkWin(arr, count + 1, size);
}
int main() {
    short itemCount = 0; 
    long long numbers[5]; 
    long long* pointer = numbers; 
    for (auto &number : numbers)
    {
        cin >> number;
        if (number <= 0)
        {
            cout << "ERROR";
            return 0;
        }
        if (itemCount != 0)
        {
            if (number > numbers[itemCount - 1])
            {
                cout << "LOSS";
                return 0;
            }
        }
        itemCount++;
    }
    if (checkWin(pointer, 0, 5)) {
        cout << "WIN";
    }
    return 0;
}
