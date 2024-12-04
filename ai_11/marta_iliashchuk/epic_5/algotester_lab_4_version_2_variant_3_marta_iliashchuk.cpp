#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> array;
    vector<int> sortedArray;
    int N, n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        array.push_back(n);
    }

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < N; k++) {
            if (array[k] % 3 == i) {
                sortedArray.push_back(array[k]);
            }
        }
    }

    // Сортування вставками
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < sortedArray.size(); j++) {
            int key = sortedArray[j];
            int k = j - 1;

            if (key % 3 == i && i % 2 == 0) {
                while (k >= 0 && sortedArray[k] % 3 == i && sortedArray[k] > key) {
                    sortedArray[k + 1] = sortedArray[k];
                    k--;
                }
            }
            else if (key % 3 == i && i == 1) {
                while (k >= 0 && sortedArray[k] % 3 == i && sortedArray[k] < key) {
                    sortedArray[k + 1] = sortedArray[k];
                    k--;
                }
            }
            sortedArray[k + 1] = key;
        }
    }

    for (int i = 0; i < sortedArray.size(); i++) {
        for (int j = i + 1; j < sortedArray.size(); j++) {
            if (sortedArray[i] == sortedArray[j]) {
                sortedArray.erase(sortedArray.begin() + j);
                j--; 
            }
        }
    }


    cout << sortedArray.size() << endl;
    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    
    return 0;
}