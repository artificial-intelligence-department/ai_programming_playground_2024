#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
private:
    T *elements;

    void checkResize(int N) {
        while (currentSize + N >= maxCapacity) {
            maxCapacity *= 2;
        }
    }

public:
    int currentSize;
    int maxCapacity;

    DynamicArray() {
        currentSize = 0;
        maxCapacity = 1;
        elements = new T[1];
    }

    void add(int index, int N, T *newElements) {
        checkResize(N);

        T *newArray = new T[maxCapacity];

        for (int i = 0; i < index; i++) {
            newArray[i] = elements[i];
        }

        for (int i = 0; i < N; i++) {
            newArray[index + i] = newElements[i];
        }

        for (int i = index; i < currentSize; i++) {
            newArray[i + N] = elements[i];
        }

        currentSize += N;
        delete[] elements;
        elements = newArray;
    }

    void remove(int index, int N) {
        T *newArray = new T[maxCapacity];
        int newSize = 0;

        for (int i = 0; i < currentSize; i++) {
            if (i < index || i >= index + N) {
                newArray[newSize] = elements[i];
                newSize++;
            }
        }

        currentSize -= N;
        delete[] elements;
        elements = newArray;
    }

    int getSize() const {
        return currentSize;
    }

    int getCapacity() const {
        return maxCapacity;
    }

    T fetch(int index) const {
        return elements[index];
    }

    void modify(int index, T value) {
        elements[index] = value;
    }

    void display(const string &separator = " ") const {
        for (int i = 0; i < currentSize; i++) {
            cout << elements[i];
            if (i < currentSize - 1) {
                cout << separator;
            }
        }
        cout << endl;
    }
};

int main() {
    DynamicArray<int> array;
    int Q;
    cin >> Q;
    while (Q--) {
        string command;
        cin >> command;
        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int *newElements = new int[N];

            for (int i = 0; i < N; i++) {
                cin >> newElements[i];
            }

            array.add(index, N, newElements);
            delete[] newElements;
        } 
        else if (command == "erase") {
            int index, N;
            cin >> index >> N;
            array.remove(index, N);
        } 
        else if (command == "size") {
            cout << array.getSize() << endl;
        } 
        else if (command == "capacity") {
            cout << array.getCapacity() << endl;
        } 
        else if (command == "get") {
            int index;
            cin >> index;
            cout << array.fetch(index) << endl;
        } 
        else if (command == "set") {
            int index, N;
            cin >> index >> N;
            array.modify(index, N);
        } 
        else if (command == "print") {
            array.display();
        }
    }
    return 0;
}
