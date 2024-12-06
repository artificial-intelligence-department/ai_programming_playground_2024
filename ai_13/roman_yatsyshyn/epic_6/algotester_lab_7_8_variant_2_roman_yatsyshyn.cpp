#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    void growCapacity(size_t minCapacity) {
        while (capacity <= minCapacity) {
            capacity *= 2;
        }
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() : data(new T[1]), capacity(1), size(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    void insert(size_t index, size_t n, const T* elements) {
        if (index > size) {
            throw out_of_range("Index out of bounds");
        }
        if (size + n >= capacity) {
            growCapacity(size + n);
        }
        for (size_t i = size; i > index; --i) {
            data[i + n - 1] = data[i - 1];
        }
        for (size_t i = 0; i < n; ++i) {
            data[index + i] = elements[i];
        }
        size += n;
    }

    void erase(size_t index, size_t n) {
        if (index >= size || index + n > size) {
            throw out_of_range("Index out of bounds");
        }
        for (size_t i = index; i < size - n; ++i) {
            data[i] = data[i + n];
        }
        size -= n;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    friend ostream& operator<<(ostream& os, const DynamicArray& arr) {
        for (size_t i = 0; i < arr.size; ++i) {
            os << arr.data[i] << " ";
        }
        return os;
    }
};

int main() {
    size_t Q;
    cin >> Q;

    DynamicArray<int> arr;
    vector<string> output;

    for (size_t q = 0; q < Q; ++q) {
        string command;
        cin >> command;

        if (command == "insert") {
            size_t index, N;
            cin >> index >> N;
            int* elements = new int[N];
            for (size_t i = 0; i < N; ++i) {
                cin >> elements[i];
            }
            arr.insert(index, N, elements);
            delete[] elements;
        }
        
        else if (command == "erase") {
            size_t index, n;
            cin >> index >> n;
            arr.erase(index, n);
        }
        
        else if (command == "size") {
            output.push_back(to_string(arr.getSize()));
        }
        
        else if (command == "capacity") {
            output.push_back(to_string(arr.getCapacity()));

        }
        
        else if (command == "get") {
            size_t index;
            cin >> index;
            output.push_back(to_string(arr[index]));
        }
        
        else if (command == "set") {
            size_t index;
            int value;
            cin >> index >> value;
            arr[index] = value;
        }
        
        else if (command == "print") {
            ostringstream oss;
            oss << arr;
            output.push_back(oss.str());
        }
        
        else {
            cerr << "Unknown command" << endl;
        }
    }

    for (const auto& line : output) {
        cout << line << endl;
    }

    return 0;
}
