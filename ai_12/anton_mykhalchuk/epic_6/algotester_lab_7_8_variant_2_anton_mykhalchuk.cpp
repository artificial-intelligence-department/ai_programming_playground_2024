#include <iostream>
#include <string>

using namespace std;

template<typename T = int>
class DynamicArray{
private: 
    T* data;
    int size;
    int capacity;

    void resize(int newCapacity){
        T* newData = new T[newCapacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() : size(0), capacity(1){
        data = new T[capacity];
    }

    ~DynamicArray(){
        delete[] data;
    }

    void insert(int index, int N, T* arr){
    if (size + N > capacity) {
        while (capacity <= size + N) {
            capacity *= 2;
        }
        resize(capacity);
    }
        for(int i = size - 1; i >= index; i--){
            data[i + N] = data[i];
        }
        for(int i = 0; i < N; i++){
            data[index + i] = arr[i];
        }
        size += N;
        if(size == capacity){
            capacity *= 2;
            resize(capacity);
        }
    }

    void erase(int index, int n){
        for(int i = index; i < size - n + n; i++){
            data[i] = data[i+n];
        }
        size -= n;
    }

    int getSize(){
        return size;
    }

    int getCapacity(){
        return capacity;
    }

    T& operator[](int index) { return data[index]; }

    friend ostream& operator<<(ostream& os, const DynamicArray& arr){
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i] << ' ';
        }
        return os;
    }

};

int main(){
DynamicArray arr;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;

        if (command == "size") {
            cout << arr.getSize() << endl;

        } else if (command == "capacity") {
            cout << arr.getCapacity() << endl;

        } else if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int* elements = new int[N];
            for (int j = 0; j < N; j++) {
                cin >> elements[j];
            }
            arr.insert(index, N, elements);

        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            arr.erase(index, n);

        } else if (command == "get") {
            int index;
            cin >> index;
            cout << arr[index] << endl;

        } else if (command == "set") {
            int index;
            int value;
            cin >> index >> value;
            arr[index] = value;

        } else if (command == "print") {
            cout << arr << endl;
        }
    }

    return 0;
}