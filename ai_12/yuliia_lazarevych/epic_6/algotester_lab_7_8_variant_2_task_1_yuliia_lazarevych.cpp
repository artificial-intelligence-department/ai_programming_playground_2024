#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T *elements;
    int currentSize;
    int currentCapacity;

    void resizeIfNeeded(int newSize) {
        while (newSize >= currentCapacity) {
            currentCapacity *= 2;
        }
        T *newArray = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = elements[i];
        }
        delete[] elements;
        elements = newArray;
    }

public:
    DynamicArray() : currentSize(0), currentCapacity(1) {
        elements = new T[currentCapacity];
    }

    ~DynamicArray() {
        delete[] elements;
    }

    void insert(int index, int count, T *newElements) {
        resizeIfNeeded(currentSize + count);
        for (int i = currentSize - 1; i >= index; --i) {
            elements[i + count] = elements[i];
        }
        for (int i = 0; i < count; ++i) {
            elements[index + i] = newElements[i];
        }
        currentSize += count;
    }

    void erase(int index, int count) {
        for (int i = index; i < currentSize - count; ++i) {
            elements[i] = elements[i + count];
        }
        currentSize -= count;
    }

    T get(int index) const {
        return elements[index];
    }

    void set(int index, T value) {
        elements[index] = value;
    }

    int size() const {
        return currentSize;
    }

    int capacity() const {
        return currentCapacity;
    }

    void print(const string &separator) const {
        for (int i = 0; i < currentSize; ++i) {
            cout << elements[i];
            if (i < currentSize - 1) cout << separator;
        }
        cout << endl;
    }
};

int main() {
    DynamicArray<int> array;

    int queryCount;
    cin >> queryCount;

    while (queryCount--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, count;
            cin >> index >> count;
            int *values = new int[count];
            for (int i = 0; i < count; ++i) {
                cin >> values[i];
            }
            array.insert(index, count, values);
            delete[] values;
        } else if (command == "erase") {
            int index, count;
            cin >> index >> count;
            array.erase(index, count);
        } else if (command == "size") {
            cout << array.size() << endl;
        } else if (command == "capacity") {
            cout << array.capacity() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            array.set(index, value);
        } else if (command == "print") {
            array.print(" ");
        }
    }

    return 0;
}
