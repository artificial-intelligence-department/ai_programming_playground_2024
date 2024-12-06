#include <iostream>
#include <string>
using namespace std;

template <typename shablon>
class DynamicMas {
private:
    int cap;
    int size;
    shablon* mas;

    void resize(int newcap) {
        shablon* newArr = new shablon[newcap];
        for (int i = 0; i < size; i++) {
            newArr[i] = mas[i];
        }
        delete[] mas;
        mas = newArr;
        cap = newcap;
    }

public:
    DynamicMas() {
        size = 0;
        cap = 1;
        mas = new shablon[cap];
    }

    ~DynamicMas() {
        delete[] mas;
    }

    void getSize() const {
        cout << size << endl;
    }

    void getCapacity() const {
        cout << cap << endl;
    }

    void insert(int pos, int count, shablon* elements) {
        if (size + count >= cap) {
            while (cap <= size + count) {
                cap *= 2;
            }
            resize(cap);
        }
        for (int i = size - 1; i >= pos; i--) {
            mas[i + count] = mas[i];
        }

        for (int i = 0; i < count; i++) {
            mas[pos + i] = elements[i];
        }
        size += count;
    }

    void erase(int pos, int count) {
        for (int i = pos; i < size - count; i++) {
            mas[i] = mas[i + count];
        }
        size -= count;
    }

    shablon& operator[](int index) {
        return mas[index];
    }

    friend ostream& operator<<(ostream& out, const DynamicMas<shablon>& dynamicMas) {
        for (int i = 0; i < dynamicMas.size; i++) {
            out << dynamicMas.mas[i] << " ";
        }
        return out;
    }
};

int main() {
    int Q;
    cin >> Q;
    DynamicMas<int> vec;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "size") {
            vec.getSize();
        } else if (command == "capacity") {
            vec.getCapacity();
        } else if (command == "insert") {
            int pos, count;
            cin >> pos >> count;
            int* elements = new int[count];
            for (int j = 0; j < count; j++) {
                cin >> elements[j];
            }
            vec.insert(pos, count, elements);
            delete[] elements;
        } else if (command == "erase") {
            int pos, count;
            cin >> pos >> count;
            vec.erase(pos, count);
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << vec[index] << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            vec[index] = value;
        } else if (command == "print") {
            cout << vec << endl;
        }
    }

    return 0;
}
