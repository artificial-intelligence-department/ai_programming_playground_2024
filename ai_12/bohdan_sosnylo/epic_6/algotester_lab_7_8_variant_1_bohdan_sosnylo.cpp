#include <iostream>
#include <string>
using namespace std;

struct DynamicMas {
private:
    int cap;
    int size;
    int* mas;

    void resize(int newcap) {
        int* mas1 = new int[newcap];
        for (int i = 0; i < size; i++) {
            mas1[i] = mas[i];
        }
        delete[] mas;
        mas = mas1;
        cap = newcap;
    }

public:
    DynamicMas() {
        size = 0;
        cap = 1;
        mas = new int[cap];
    }

    ~DynamicMas() {
        delete[] mas;
    }

    void getsize() {
        cout << size << endl;
    }

    void getcapacity() {
        cout << cap << endl;
    }

    void insert(int a, int N, int* numb) {
        if (size + N >= cap) {
            while (cap <= size + N) {
                cap *= 2;
            }
            resize(cap);
        }
        for (int i = size - 1; i >= a; i--) {
            mas[i + N] = mas[i];
        }

        for (int i = 0; i < N; i++) {
            mas[a + i] = numb[i];
        }
        size += N;
       
    }
    void erase(int a, int n) {
        for (int i = a; i < size - n; i++) {
            mas[i] = mas[i + n];
        }
        size -= n;
    }

    int& operator[](int a) {
        return mas[a];
    }

    friend ostream& operator<<(ostream& out, const DynamicMas& arr) {
        for (int i = 0; i < arr.size; i++) {
            out << arr.mas[i] << " ";
        }
        return out;
    }
};

int main() {
    int Q;
    cin >> Q;
    DynamicMas vec;

    for (int i = 0; i < Q; i++) {
        string com;
        cin >> com;
        if (com == "size") {
            vec.getsize();
        } else if (com == "capacity") {
            vec.getcapacity();
        } else if (com == "insert") {
            int a, b;
            cin >> a >> b;
            int* elem = new int[b];
            for (int j = 0; j < b; j++) {
                cin >> elem[j];
            }
            vec.insert(a, b, elem);
            delete[] elem;
        } else if (com == "erase") {
            int a, n;
            cin >> a >> n;
            vec.erase(a, n);
        } else if (com == "get") {
            int a;
            cin >> a;
            cout << vec[a] << endl;
        } else if (com == "set") {
            int index, value;
            cin >> index >> value;
            vec[index] = value;
        } else if (com == "print") {
            cout << vec << endl;
        }
    }

    return 0;
}
