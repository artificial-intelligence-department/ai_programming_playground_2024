#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void show_array(const vector<int>& array){
    cout << array.size() << endl;
    for (const int& num : array) {
        cout << num << " ";
    }
    cout << endl;
}

void insert_sorted(vector<int>& array, int value, int& p1, int& p2, int remainder ) {
    bool is_сopy = false;

    if (remainder  == 0) {
        if (p1 == 0 || array[p1 - 1] < value) {
            array.insert(array.begin() + p1, value);
        } else {
            int l = 0, r = p1 - 1, n = r / 2;
            while (l < r) {
                int& val = array[n];
                if (val < value) {
                    l = n + 1;
                } else if (val > value) {
                    r = n;
                } else {
                    is_сopy = true;
                    break;
                }
                n = (r + l) / 2;
            }
            if (l >= r) {
                if (array[l] != value) array.insert(array.begin() + l, value);
                else is_сopy = true;
            }
        }
        if (!is_сopy) {
            p1++;
            p2++;
        }

    } 

    else if (remainder  == 1) {
        if (p1 == p2 || p2 == 0 || array[p2 - 1] > value) {
            array.insert(array.begin() + p2, value);
        } else {
            int l = p1, r = p2 - 1, n = (r + l) / 2;
            while (l < r) {
                int& val = array[n];
                if (val > value) {
                    l = n + 1;
                } else if (val < value) {
                    r = n;
                } else {
                    is_сopy = true;
                    break;
                }
                n = (r + l) / 2;
            }
            if (l >= r) {
                if (array[l] != value) array.insert(array.begin() + l, value);
                else is_сopy = true;
            }
        }
        if (!is_сopy) {
            p2++;
        }
    } 

    else {
        const int SIZE = array.size();
        if (p2 == SIZE || SIZE == 0 || array[SIZE - 1] < value) {
            array.push_back(value);
        } else {
            int l = p2, r = SIZE - 1, n = (r + l) / 2;
            while (l < r) {
                int& val = array[n];
                if (val < value) {
                    l = n + 1;
                } else if (val > value) {
                    r = n;
                } else {
                    is_сopy = true;
                    break;
                }
                n = (r + l) / 2;
            }
            if (l >= r) {
                if (array[l] != value) array.insert(array.begin() + l, value);
                else is_сopy = true;
            }
        }
    }
}

int main() {
    int size;
    cin >> size;
    vector<int> array;
    array.reserve(10 * 10 * 10); 

    int p1 = 0, p2 = 0;
    int temp;

    for (int i = 0; i < size; i++) {
        cin >> temp;  
        insert_sorted(array, temp, p1, p2, temp % 3);
    }

    show_array(array);

    return 0;
}