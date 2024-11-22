#include <iostream>
#include <vector>
using namespace std;

void printRing(const vector<int>& ring, int k, bool left) {
    int n = ring.size();
    cout << "Ring printed " << (left ? "left" : "right") << " from index " << k << ": ";
    for (int i = 0; i < n; ++i) {
        cout << ring[(left ? k - i + n : k + i) % n] << " ";
    }
    cout << endl;
}

void insertZeros(vector<int>& ring) {
    for (int i = 0; i < ring.size(); ++i) {
        if (i % 5 == 0) {
            ring.insert(ring.begin() + i + 1, 0);
            ++i;
        }
    }
}

int main() {
    int size, k;
    cout << "Enter the size of the ring: ";
    cin >> size;
    cout << "Enter the starting index (0-based): ";
    cin >> k;

    vector<int> ring(size);
    cout << "Enter the elements of the ring: ";
    for (int i = 0; i < size; ++i) {
        cin >> ring[i];
    }

    printRing(ring, k, true);
    insertZeros(ring);
    printRing(ring, k, false);

    return 0;
}
