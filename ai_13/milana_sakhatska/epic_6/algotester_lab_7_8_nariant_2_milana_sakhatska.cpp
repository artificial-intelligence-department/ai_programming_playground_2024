#include <iostream>
#include <string>

using namespace std;

template<typename T = int>
class DArray {
private:
    T* d;
    int sz;
    int cap;

    void resize(int newCap) {
        T* newD = new T[newCap];
        for (int i = 0; i < sz; i++) {
            newD[i] = d[i];
        }
        delete[] d;
        d = newD;
        cap = newCap;
    }

public:
    DArray() : sz(0), cap(1) {
        d = new T[cap];
    }

    ~DArray() {
        delete[] d;
    }

    void insert(int idx, int n, T* elems) {
        if (sz + n > cap) {
            while (cap <= sz + n) {
                cap *= 2;
            }
            resize(cap);
        }
        for (int i = sz - 1; i >= idx; i--) {
            d[i + n] = d[i];
        }
        for (int i = 0; i < n; i++) {
            d[idx + i] = elems[i];
        }
        sz += n;
        if (sz == cap) {
            cap *= 2;
            resize(cap);
        }
    }

    void erase(int idx, int n) {
        for (int i = idx; i < sz - n; i++) {
            d[i] = d[i + n];
        }
        sz -= n;
    }

    int getSize() const {
        return sz;
    }

    int getCapacity() const {
        return cap;
    }

    T& operator[](int idx) { return d[idx]; }

    friend ostream& operator<<(ostream& os, const DArray& arr) {
        for (int i = 0; i < arr.sz; i++) {
            os << arr.d[i] << ' ';
        }
        return os;
    }
};

int main() {
    DArray<int> arr;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "size") {
            cout << arr.getSize() << endl;
        } else if (cmd == "capacity") {
            cout << arr.getCapacity() << endl;
        } else if (cmd == "insert") {
            int idx, n;
            cin >> idx >> n;
            int* elems = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> elems[j];
            }
            arr.insert(idx, n, elems);
            delete[] elems;
        } else if (cmd == "erase") {
            int idx, n;
            cin >> idx >> n;
            arr.erase(idx, n);
        } else if (cmd == "get") {
            int idx;
            cin >> idx;
            cout << arr[idx] << endl;
        } else if (cmd == "set") {
            int idx, val;
            cin >> idx >> val;
            arr[idx] = val;
        } else if (cmd == "print") {
            cout << arr << endl;
        }
    }

    return 0;
}
