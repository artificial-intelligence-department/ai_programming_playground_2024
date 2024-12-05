#include <iostream>
#include <vector>

using namespace std;

class CircularArray {
private:
    vector<int> elements;

public:

    CircularArray(const vector<int>& init) : elements(init) {}

    int get(int index) const {
        int n = elements.size();
        return elements[(index % n + n) % n];
    }

    void insertAfter(int index, int value) {
        int pos = (index + 1) % elements.size();
        elements.insert(elements.begin() + pos, value);
    }

    void print() const {
        for (size_t i = 0; i < elements.size(); ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    int size() const {
        return elements.size();
    }

    int operator[](int index) const {
        return get(index);
    }
};

void printLeftFromK(const CircularArray& array, int k) {
    vector<int> result;
    int n = array.size();
    for (int i = k; i > k - n; --i) {
        result.push_back(array[i]);
    }
    cout << "Кільце вліво від K: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void addZerosAfterMultiplesOfFive(CircularArray& array) {
    int shift = 0; // Зсув через додані елементи
    for (int i = 0; i < array.size(); ++i) {
        if ((i % 5) == 0) {
            array.insertAfter(i + shift, 0);
            ++shift;
        }
    }
}

void printRightFromK(const CircularArray& array, int k) {
    vector<int> result;
    int n = array.size();
    for (int i = k; i < k + n; ++i) {
        result.push_back(array[i]);
    }
    cout << "Кільце вправо від K: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> init;
    for (int i = 1; i <= 20; ++i) {
        init.push_back(i);
    }
    CircularArray circularArray(init);

    cout << "Початковий масив: ";
    circularArray.print();

    int K = 5;
    printLeftFromK(circularArray, K);

    addZerosAfterMultiplesOfFive(circularArray);
    cout << "Після додавання нулів: ";
    circularArray.print();

    printRightFromK(circularArray, K);

    return 0;
}