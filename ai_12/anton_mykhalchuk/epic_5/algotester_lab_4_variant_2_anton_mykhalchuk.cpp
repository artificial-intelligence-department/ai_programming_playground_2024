#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSortArr(vector<int>& vec) {
    bool swapped;
    for (int i = 0; i < vec.size() - 1 ; i++) {
        swapped = false;
        for (int j = 0; j < vec.size() - i -1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
} 

vector<int> uniqueArr(const vector<int>& vec) {
    vector<int> newArr;
    for (int i = 0; i < vec.size(); i++) {
        bool single = true;
        for (int j = 0; j < newArr.size(); j++) {
            if (vec[i] == newArr[j]) {
                single = false;
            }
        }

        if (single) {
            newArr.push_back(vec[i]);
        }
    }

    return newArr;
}

void rotateArr(vector<int>& vec, int k) {
    k %= vec.size();
    int temp;
    for (int i = 0; i < k; i++) {
        temp = vec[0];
        vec.erase(vec.begin());
        vec.push_back(temp);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    bubbleSortArr(numbers);

    numbers = uniqueArr(numbers);

    rotateArr(numbers, k);

    cout << numbers.size() << endl;

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << ' ';
    }
}    