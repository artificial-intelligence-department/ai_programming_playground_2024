#include <iostream>
using namespace std;

template< typename T >
class Array {
    private:
    T* data;
    
    public:
    int size, capacity;

    Array() {
        size = 0;
        capacity = 1;
        data = new T[1];
    }

    void insert(int index, int N, T *elements) {
        while (size + N >= capacity) {
            capacity *= 2;
        }

        T *temp = new T[capacity];

        for (int i = 0; i < index; i++) {
            temp[i] = data[i];
        }

        for (int i = 0; i < N; i++) {
            temp[index + i] = elements[i];
        }

        for (int i = index; i < size; i++) {
            temp[i + N] = data[i];
        }

        size += N;
        data = temp;
    }

    void erase(int index, int N) {
        T *temp = new T[capacity];
        int reSize = 0;

        for (int i = 0; i < size; i++) {
            if (i < index || i >= index + N) {
                temp[reSize] = data[i];
                reSize++;
            }
        }
        size -= N;
        data = temp;
    }

    T& operator[](int index) {
        return data[index];
    }

    int ShowSize() {
        return size;
    }

    int ShowCapacity() {
        return capacity;
    }

    friend ostream& operator<<(ostream& ostr, const Array& arr) {
        for (int i = 0; i < arr.size; i++) {
            ostr << arr.data[i];
            if (i < arr.size - 1) {
                ostr << " ";
            }
        }
        return ostr;
    }

    ~Array() {
        delete[] data;
    }
};

int main(){
    int Q;
    cin >> Q;
    Array<int> arr;

    string command;
    int index, N;
    while (Q--){
        cin >> command;
        if (command == "insert"){
            cin >> index >> N;
            int elems[N];

            for (int i = 0; i < N; i++) {
                cin >> elems[i];
            }

            arr.insert(index, N, elems);

        } else if (command == "erase"){
            cin >> index >> N;
            arr.erase(index, N);

        } else if (command == "size"){
            cout << arr.ShowSize() << endl;

        } else if (command == "capacity"){
            cout << arr.ShowCapacity() << endl;

        } else if (command == "get"){
            cin >> index;
            cout << arr[index] << endl;

        } else if (command == "set"){
            cin >> index >> N;
            arr[index] = N;

        } else if (command == "print"){
            cout << arr << endl;
        }
    }

    return 0;
}