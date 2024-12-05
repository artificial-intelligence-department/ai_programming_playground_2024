#include <iostream>

using namespace std;

template<typename T>

class dynamicArray {
private:
    T* data;
    int size;
    int capacity;

    void remSize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    dynamicArray() : size(0), capacity(1) {
        data = new T[capacity];
    }

    ~dynamicArray() {
        delete[] data;
    }

    void insert(int index, int n, T* values) {
        if (size + n > capacity) {
            int newCapacity = capacity;
            while (size + n >= newCapacity) {
                newCapacity *= 2;
            }
            remSize(newCapacity);
        }

        for (int i = size - 1; i >= index; i--) {
            data[i + n] = data[i];
        }
        for (int i = 0; i < n; i++) {
            data[index + i] = values[i];
        }
        size += n;

        if (size == capacity) {
            capacity *= 2;
            remSize(capacity);
        }
    }

    void erase(int index, int n) {
        for (int i = index + n; i < size; i++) {
            data[i - n] = data[i];
        }
        size -= n;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("ERROR");
        }
        return data[index];
    }

    friend ostream& operator<<(ostream& os, const dynamicArray& arr) {
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i] << (i < arr.size - 1 ? " " : "");
        }
        return os;
    }
};

int main() {
    dynamicArray<int> arr;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, n;
            cin >> index >> n;
            int* values = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> values[j];
            }
            arr.insert(index, n, values);
            delete[] values;
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            arr.erase(index, n);
        } else if (command == "size") {
            cout << arr.getSize() << endl;
        } else if (command == "capacity") {
            cout << arr.getCapacity() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << arr[index] << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            arr[index] = value;
        } else if (command == "print") {
            cout << arr << endl;
        }
    }

    return 0;
}
