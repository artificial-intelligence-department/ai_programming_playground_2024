#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
    private:
        int dynArrSize;
        int dynArrCapacity;
        T *dynArr;

    public:
        DynamicArray() {
            dynArrSize = 0;
            dynArrCapacity = 1;
            dynArr = new T[1];
        }

        ~DynamicArray() {delete[] dynArr;}

        void resize(int N) {
            while (dynArrSize + N >= dynArrCapacity) {
                dynArrCapacity *= 2;
            }
        }

        void insert(int index, int N, T* values) {
            resize(N);

            for (int i = dynArrSize - 1; i >= index; i--) {
                dynArr[i + N] = dynArr[i];
            }

            for (int i = 0; i < N; i++) {
                dynArr[index + i] = values[i];
            }

            dynArrSize += N;

            return;
        }

        void erase(int index, int N) {
            T *temp = new T[dynArrCapacity];
            int newDynArrSize = 0;

            for (int i = 0; i < dynArrSize; i++) {
                if (i < index || i >= index + N) {
                    temp[newDynArrSize] = dynArr[i];
                    newDynArrSize++;
                }
            }
    
            dynArrSize -= N;
            delete[] dynArr;
            dynArr = temp;

            return;
        }

        void size() const {
            cout << dynArrSize << endl;
            return;
        }

        void capacity() const {
            cout << dynArrCapacity << endl;
            return;
        }

        void get(int index) {
            cout << dynArr[index] << endl;
            return;
        }

        void set(int index, int value) {
            dynArr[index] = value;
            return;
        }

        void print() {
            for (int i = 0; i < dynArrSize; i++) cout << dynArr[i] << " ";
            return;
        }
};

int main() {
    DynamicArray<int> arr;

    int Q;
    cin >> Q;

    while (Q--) {

        string choise;
        cin >> choise;

        if (choise == "insert") {
            int index, N;
            cin >> index >> N;

            int *values = new int[N];
            for (int i = 0; i < N; i++) cin >> values[i];

            arr.insert(index, N, values);

        } else if (choise == "erase") {
            int index, N;
            cin >> index >> N;

            arr.erase(index, N);

        } else if (choise == "size") {
            arr.size();

        } else if (choise == "capacity") {
            arr.capacity();

        } else if (choise == "get") {
            int index;
            cin >> index;

            arr.get(index);

        } else if (choise == "set") {
            int index, value;
            cin >> index >> value;

            arr.set(index, value);

        } else if (choise == "print") arr.print();
    }
}
