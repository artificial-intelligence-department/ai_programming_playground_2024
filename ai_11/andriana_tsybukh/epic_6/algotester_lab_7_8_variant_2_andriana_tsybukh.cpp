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

    void insert(int index, int N, T *elements) {
        while (size + N >= capacity)
            capacity *= 2;
        T *temp = new T[capacity];

        for (int i = 0; i < index; i++)
            temp[i] = data[i];

        for (int i = 0; i < N; i++)
            temp[index + i] = elements[i];

        for (int i = index; i < size; i++)
            temp[i + N] = data[i];
            
        this->size += N;
        delete[] data;
        data = temp;
    }

    void erase(int index, int N) {
        T *temp = new T[capacity];
        int newSize = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (i < index || i >= index + N)
            {
                temp[newSize] = data[i];
                newSize++;
            }
        }
        this->size -= N;
        delete[] data;
        data = temp;
    }

    T get(int index) {
        return this->data[index];
    }

    void set(int index, T value) {
        this->data[index] = value;
    }

    void print(const string &separator) {
        for (int i = 0; i < this->size; i++) {
            cout << data[i];
            if (i < size - 1) {
                cout << separator;
            }
        }
        cout << endl;
    }
};

int main() {
    dynamicArray<int> array;

    int Q;
    cin >> Q;

    while (Q--) {


        string option;
        cin >> option;
        if (option == "insert") {
            int index, N;
            cin >> index >> N;
            int *elements = new int[N];

            for (int i = 0; i < N; i++) {
                cin >> elements[i];
            }

            array.insert(index, N, elements);
            delete[] elements;
        } else if (option == "erase") {
            int index, N;
            cin >> index >> N;
            array.erase(index, N);
        } else if (option == "size") {
            cout << array.size << endl;
        } else if (option == "capacity") {
            cout << array.capacity << endl;
        } else if (option == "get") {
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        } else if (option == "set") {
            int index, N;
            cin >> index >> N;
            array.set(index, N);
        } else if (option == "print") {
            array.print(" ");
        }
    }
    return 0;
}