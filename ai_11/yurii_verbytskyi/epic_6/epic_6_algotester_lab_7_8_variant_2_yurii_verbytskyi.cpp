#include <iostream>
using namespace std;

template <class T>
class dynamicArray {
private:
    T *data;

public:
    int size;
    int capacity;

    dynamicArray() {
        this->size = 0;
        this->capacity = 1;
        this->data = new T[1];
    }

    void insert(int index, int quantity, T *elements) {
        while (size + quantity >= capacity)
            capacity *= 2;
        T *temp = new T[capacity];

        for (int i = 0; i < index; i++)
            temp[i] = data[i];

        for (int i = 0; i < quantity; i++)
            temp[i + index] = elements[i];

        for (int i = index; i < size; i++)
            temp[i + quantity] = data[i];
            
        this->size += quantity;
        delete[] data;
        data = temp;
    }

    void erase(int index, int quantity) {
        T *temp = new T[capacity];
        int newSize = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (i < index || i >= index + quantity)
            {
                temp[newSize] = data[i];
                newSize++;
            }
        }
        this->size -= quantity;
        delete[] data;
        data = temp;
    }

    T get(int index) {
        return this->data[index];
    }

    void set(int index, T value) {
        this->data[index] = value;
    }

    void print(const string &space) {
        for (int i = 0; i < this->size; i++) {
            cout << data[i];
            if (i < size - 1) cout << space;
        }
        cout << endl;
    }
};

int main() {
    dynamicArray<int> array;

    int Q;
    cin >> Q;

    while (Q--) {


        string command;
        cin >> command;
        if (command == "insert") {
            int index, quantity;
            cin >> index >> quantity;
            int *elements = new int[quantity];

            for (int i = 0; i < quantity; i++) {
                cin >> elements[i];
            }

            array.insert(index, quantity, elements);
            delete[] elements;
        } else if (command == "erase") {
            int index, quantity;
            cin >> index >> quantity;
            array.erase(index, quantity);
        } else if (command == "size") {
            cout << array.size << endl;
        } else if (command == "capacity") {
            cout << array.capacity << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        } else if (command == "set") {
            int index, quantity;
            cin >> index >> quantity;
            array.set(index, quantity);
        } else if (command == "print") {
            array.print(" ");
        }
    }
    return 0;
}