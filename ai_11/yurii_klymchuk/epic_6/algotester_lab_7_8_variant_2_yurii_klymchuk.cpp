#include <iostream>
using namespace std;

//Usage of class template
template <class T>
class DynamicArray {
private:
    T *data;
    //Resize with growth factor 2
    void ResizeIfNeeded(int N) {
        while (size + N >= capacity) {
            capacity *= 2;
        }
    }

public:
    int size;
    int capacity;
    //Constructor
    DynamicArray() {
        size = 0;
        capacity = 1;
        data = new T[1];
    }
    //Inserting multiple elements into array
    void insert(int index, int N, T *elements) {
        ResizeIfNeeded(N);

        T *temporary = new T[capacity];

        for (int i = 0; i < index; i++) {
            temporary[i] = data[i];
        }

        for (int i = 0; i < N; i++) {
            temporary[index + i] = elements[i];
        }

        for (int i = index; i < size; i++) {
            temporary[i + N] = data[i];
        }
        //Update the size, delete old data, add new
        size += N;
        delete[] data;
        data = temporary;
    }

    //Erasing multiple elements
    void erase(int index, int N) {
        T *temporary = new T[capacity];
        int newSize = 0;

        //Deleting elements by index
        for (int i = 0; i < size; i++) {
            if (i < index || i >= index + N) {
                temporary[newSize] = data[i];
                newSize++;
            }
        }
        //Update the size and data
        size -= N;
        delete[] data;
        data = temporary;
    }

    int Size() const {
        return size;
    }

    int Capacity() const {
        return capacity;
    }
    //Return element by its index
    T get(int index) const {
        return data[index];
    }

    //Rewrite the value by index
    void set(int index, T value) {
        data[index] = value;
    }

    //Function to display array
    void print(const string &separator = " ") const {
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) {
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
        //Processing users input
        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int *elements = new int[N];

            for (int i = 0; i < N; i++) {
                cin >> elements[i];
            }

            array.insert(index, N, elements);
            delete[] elements;
        } 
        else if (command == "erase") {
            int index, N;
            cin >> index >> N;
            array.erase(index, N);
        } 
        else if (command == "size") {
            cout << array.Size() << endl;
        } 
        else if (command == "capacity") {
            cout << array.Capacity() << endl;

        } 
        else if (command == "get") {
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        } 
        else if (command == "set") {
            int index, N;
            cin >> index >> N;
            array.set(index, N);
        } 
        else if (command == "print") {
            array.print();
        }
    }
    return 0;
}

