#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printRingLeft(const vector<int>& ring, int start) {

    int size = ring.size();
    int index = start;


    do {

        cout << ring[index] << " ";
        index = (index - 1 + size) % size;

    } while (index != (start - 1 + size) % size);

    cout << endl;
}

void printRingRight(const vector<int>& ring, int start) {

    int size = ring.size();
    int index = start;


    do {

        cout << ring[index] << " ";
        index = (index + 1) % size;

    } while (index != (start + 1) % size);

    cout << endl;
}

void deleteMaxElements(vector<int>& ring) {

    int maxElement = *max_element(ring.begin(), ring.end());
    ring.erase(remove(ring.begin(), ring.end(), maxElement), ring.end());

}

int main() {

    int n, k;

    cout << "Введіть розмір масиву (n): ";

    cin >> n;

    vector<int> ring(n);

    cout << "Введіть елементи масиву: ";

    for (int i = 0; i < n; i++) {

        cin >> ring[i];

    }

    cout << "Введіть початковий індекс (K): ";

    cin >> k;

    k = (k % n + n) % n; 

    cout << "Масив по кільцю вліво від K до K-1: ";

    printRingLeft(ring, k);


    deleteMaxElements(ring);


    cout << "Масив після видалення максимальних елементів по кільцю вправо від K до K+1: ";


    printRingRight(ring, k);




    return 0;
}
