#include <iostream>
#include <string>

using namespace std;

template <class T>
class DynamicMas {
private:
    int s;
    int capacity;
    T* array;

    void resize(int size) {
        if (size >= capacity) {
            while (size >= capacity)
                capacity *= 2;

            T* newArray = new T[capacity];
            for (int i = 0; i < s; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    DynamicMas() : s(0), capacity(1), array(new T[1]) {}

    ~DynamicMas() { delete[] array; }

    int cap() const { return capacity; }
    int size() const { return s; }

    void insert(int index, int num, T* array2) {
        resize(s + num);

        for (int i = s - 1; i >= index; i--)
            array[i + num] = array[i];

        for (int i = 0; i < num; i++)
            array[index + i] = array2[i];

        s += num;
    }

    void erase(int index, int n) {
        for (int i = index; i < s - n; i++)
            array[i] = array[i + n];

        s -= n;
    }

    T& operator[](int index) { return array[index]; }
    T get(int index) const { return array[index]; }
    void set(int index, T num) { array[index] = num; }

    friend ostream& operator<<(ostream& out, const DynamicMas<T>& arr) {
        for (int i = 0; i < arr.s; ++i)
            out << arr.array[i] << " ";

        return out;
    }

    void print() const { cout << *this << "\n"; }
};

int main() {
    int Q;
    cin >> Q;
    DynamicMas<int> arr;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "size")
            cout << arr.size() << "\n";

        else if (command == "capacity")
            cout << arr.cap() << "\n";

        else if (command == "print")
            arr.print();

        else if (command == "get") {
            int num;
            cin >> num;
            cout << arr.get(num) << "\n";
        }

        else if (command == "set") {
            int index, value;
            cin >> index >> value;
            arr.set(index, value);
        }

        else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            arr.erase(index, n);
        }

        else {
            int index, num;
            cin >> index >> num;

            int* tempArr = new int[num];
            for (int j = 0; j < num; ++j)
                cin >> tempArr[j];

            arr.insert(index, num, tempArr);
            delete[] tempArr;
        }
    }

    return 0;
}

