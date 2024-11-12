#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum Operation {
    INSERT,
    ERASE,
    SIZE,
    CAPACITY,
    GET,
    SET,
    PRINT,
    UNKNOWN
};

Operation getOperation(const string& command) {
    if (command == "insert") return INSERT;
    if (command == "erase") return ERASE;
    if (command == "size") return SIZE;
    if (command == "capacity") return CAPACITY;
    if (command == "get") return GET;
    if (command == "set") return SET;
    if (command == "print") return PRINT;
    return UNKNOWN;
}

template<typename T = int> //int by default
class DynamicArray{
private: 
    T* data;
    int size_;
    int capacity_;

    void resize(int newCapacity){
        T* newData = new T[newCapacity];
        //copy
        for(int i = 0; i < size_; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity_ = newCapacity;
    }

public:
    DynamicArray() : size_(0), capacity_(1){
        data = new T[capacity_];
    }

    ~DynamicArray(){
        delete[] data;
    }

    void insert(int index, int N, T* arr){
    if (size_ + N > capacity_) {
        while (capacity_ <= size_ + N) {
            capacity_ *= 2;
        }
        resize(capacity_);
    }
        //move a part of the array to the right to insert by index
        for(int i = size_ - 1; i >= index; i--){
            data[i + N] = data[i];
        }
        for(int i = 0; i < N; i++){
            data[index + i] = arr[i];
        }
        size_ += N;
        if(size_ == capacity_){
            capacity_ *= 2;
            resize(capacity_);
        }
    }

    void erase(int index, int n){
        for(int i = index; i < size_ - n + n; i++){
            data[i] = data[i+n];
        }
        size_ -= n;
    }

    int size(){
        return size_;
    }

    int capacity(){
        return capacity_;
    }

    //eccess elements by index
    T& operator[](int index) { return data[index]; }

    //functionality to be able to cout by using <<
    friend ostream& operator<<(ostream& os, const DynamicArray& arr){
        for (int i = 0; i < arr.size_; i++) {
            os << arr.data[i] << ' ';
        }
        return os;
    }

};

int main(){
    int Q;
    cin >> Q;
    DynamicArray<int> dynArr;

    for(int i = 0; i < Q; i++){
        string option;
        cin >> option;
        Operation operation = getOperation(option);

        switch (operation) {
            case INSERT: {
                int index, N;
                cin >> index >> N;
                int arr[N];
                for(int i = 0; i < N; i++){
                    cin >> arr[i];
                }
                dynArr.insert(index, N, arr);
                break;
            }
            case ERASE: {
                int index, n;
                cin >> index >> n;
                dynArr.erase(index, n);
                break;
            }
            case SIZE: {
                cout << dynArr.size() << endl;
                break;
            }
            case CAPACITY: {
                cout << dynArr.capacity() << endl;
                break;
            }
            case GET: {
                int index;
                cin >> index;
                cout << dynArr[index] << endl;
                break;
            }
            case SET: {
                int index, value;
                cin >> index >> value;
                dynArr[index] = value;
                break;
            }
            case PRINT: {
                cout << dynArr << endl;
                break;
            }
            default:
                break;
        }
    }
}