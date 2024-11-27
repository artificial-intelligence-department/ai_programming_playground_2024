#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &r, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (r[j] > r[j + 1]) {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cin >> size;
    vector<int> r(size);
    for(int i = 0; i < size; i++){
        cin >> r[i];
    }

    vector<int> new_r1;
    vector<int> new_r2;

    bubbleSort(r, size);
    
    
    for (int i = 0; i < size; i++) {
        new_r1.push_back(r[i]);
    }
    new_r1.pop_back();
    int min1 = new_r1[0], max1 = new_r1[0];
    for (int i = 0; i < size-1; i++) {
        if (new_r1[i] < min1) {
            min1 = new_r1[i];
        }
        if (new_r1[i] > max1) {
            max1 = new_r1[i];
        }
    }
    int difference1 = max1 - min1;

    for (int i = size - 1; i >= 0; i--) {
        new_r2.push_back(r[i]);
    }
    new_r2.pop_back();
    int min2 = new_r2[0], max2 = new_r2[0];
    for (int i = 0; i < size-1; i++) {
        if (new_r2[i] < min2) {
            min2 = new_r2[i];
        }
        if (new_r2[i] > max2) {
            max2 = new_r2[i];
        }
    }
    int difference2 = max2 - min2;

    if(difference1 < difference2){
        cout << difference1;
    } else cout << difference2;

    

    return 0;
}
