#include <iostream>
#include <vector>
using namespace std;

void printRing(const vector<int>& ring, int k) {
    for (int i = 0; i < ring.size(); i++) {
        cout << ring[(i + k) % ring.size()] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> ring;
    int k, siz, firstEl, lastEl;

    cin >> siz >> k >> firstEl >> lastEl;
    for (int m = 0; m < siz; m++) {
        int newEl;
        cin >> newEl;
        ring.push_back(newEl);
    }

    printRing(ring, k);
    ring.insert(ring.begin(), firstEl);
    ring.push_back(lastEl);

    for (int n = ring.size() - 1; n >= 0; n--) {
        if (ring[n] % 2 == 0) {
            ring.erase(ring.begin() + n);
        }
    }

    printRing(ring, k);

    return 0;
}
