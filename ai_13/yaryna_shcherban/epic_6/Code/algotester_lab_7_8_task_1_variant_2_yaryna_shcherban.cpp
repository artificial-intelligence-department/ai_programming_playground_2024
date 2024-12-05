#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct DynamicArray {
    T *arr;
    int size;
    int capacity;
    DynamicArray() {
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }
    ~DynamicArray() {
        delete[] arr;
    }
};

template <typename T>
void insert(DynamicArray<T> &array, int index, int amount, T *toInsert) {
    while (array.size + amount >= array.capacity) {
        array.capacity *= 2;
    }
    T *temp = new T[array.capacity];
    for (int i = 0; i < index; i++) {
        temp[i] = array.arr[i];
    }
    for (int i = 0; i < amount; i++) {
        temp[index + i] = toInsert[i];
    }
    for (int i = index; i < array.size; i++) {
        temp[i + amount] = array.arr[i];
    }
    array.size += amount;
    delete[] array.arr;
    array.arr = temp;
}

template <typename T>
void erase(DynamicArray<T> &array, int index, int amount) {
    T *temp = new T[array.capacity];
    int acc = 0;

    for (int i = 0; i < array.size; i++) {
        if (i < index || i >= index + amount) {
            temp[acc] = array.arr[i];
            acc++;
        }
    }
    array.size -= amount;
    delete[] array.arr;
    array.arr = temp;
}

template <typename T>
T get(const DynamicArray<T> &array, int index) {
    return array.arr[index];
}

template <typename T>
void set(DynamicArray<T> &array, int index, T value) {
    array.arr[index] = value;
}

template <typename T>
void print(const DynamicArray<T> &array, const string &separator) {
    for (int i = 0; i < array.size; i++) {
        cout << array.arr[i] << separator;
    }
    cout << endl;
}

int main() {
    DynamicArray<int> arr;
    int q;
    cin >> q;
    while (q--) {
        string line;
        cin >> line;
        if (line == "insert") {
            int index, N;
            cin >> index >> N;
            int *temp = new int[N];
            for (int i = 0; i < N; i++) {
                cin >> temp[i];
            }
            insert(arr, index, N, temp);
            delete[] temp;
        } else if (line == "erase") {
            int index, N;
            cin >> index >> N;
            erase(arr, index, N);
        } else if (line == "size") {
            cout << arr.size << endl;
        } else if (line == "capacity") {
            cout << arr.capacity << endl;
        } else if (line == "get") {
            int i;
            cin >> i;
            cout << get(arr, i) << endl;
        } else if (line == "set") {
            int i, value;
            cin >> i >> value;
            set(arr, i, value);
        } else if (line == "print") {
            print(arr, " ");
        }
    }
    return 0;
}