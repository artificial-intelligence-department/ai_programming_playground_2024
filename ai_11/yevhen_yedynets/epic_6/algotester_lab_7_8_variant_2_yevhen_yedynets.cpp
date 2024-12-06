#include <iostream>

using namespace std;

template <class T>
class DynamicArray {
private:
    T *elements;

public:
    int currentSize;
    int currentCapacity;

    DynamicArray() {
        this->currentSize = 0;
        this->currentCapacity = 1;
        this->elements = new T[1];
    }

    void insertAt(int pos, int count, T *values) {
        while (currentSize + count >= currentCapacity)
            currentCapacity *= 2;
        T *tempArray = new T[currentCapacity];

        for (int i = 0; i < pos; i++)
            tempArray[i] = elements[i];

        for (int i = 0; i < count; i++)
            tempArray[i + pos] = values[i];

        for (int i = pos; i < currentSize; i++)
            tempArray[i + count] = elements[i];
            
        this->currentSize += count;
        delete[] elements;
        elements = tempArray;
    }

    void removeAt(int pos, int count) {
        T *tempArray = new T[currentCapacity];
        int newSize = 0;
        for (int i = 0; i < this->currentSize; i++)
        {
            if (i < pos || i >= pos + count)
            {
                tempArray[newSize] = elements[i];
                newSize++;
            }
        }
        this->currentSize -= count;
        delete[] elements;
        elements = tempArray;
    }

    T getElement(int pos) {
        return this->elements[pos];
    }

    void setElement(int pos, T value) {
        this->elements[pos] = value;
    }

    void display(const string &separator) {
        for (int i = 0; i < this->currentSize; i++) {
            cout << elements[i];
            if (i < currentSize - 1) cout << separator;
        }
        cout << endl;
    }
};

int main() {
    DynamicArray<int> arr;

    int numCommands;
    cin >> numCommands;

    while (numCommands--) {
        string command;
        cin >> command;
        if (command == "insert") {
            int pos, count;
            cin >> pos >> count;
            int *values = new int[count];

            for (int i = 0; i < count; i++) {
                cin >> values[i];
            }

            arr.insertAt(pos, count, values);
            delete[] values;
        } else if (command == "erase") {
            int pos, count;
            cin >> pos >> count;
            arr.removeAt(pos, count);
        } else if (command == "size") {
            cout << arr.currentSize << endl;
        } else if (command == "capacity") {
            cout << arr.currentCapacity << endl;
        } else if (command == "get") {
            int pos;
            cin >> pos;
            cout << arr.getElement(pos) << endl;
        } else if (command == "set") {
            int pos, value;
            cin >> pos >> value;
            arr.setElement(pos, value);
        } else if (command == "print") {
            arr.display(" ");
        }
    }
    return 0;
}