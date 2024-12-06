#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct MyArray {

    int size = 0;
    int capacity = 1;
    Type *A;


    MyArray() {
        A = new Type[1];
    }


    void Insert(int index, int arr[], int N) {

        if (capacity > size + N) {

            for (int i = size - 1; i > index - 1; i--) {
                A[i + N] = A[i];
            }

            for (int i = 0; i <  N; ++i) {
                A[i+index]=arr[i];
            }

            size += N;

        } else {

            while (capacity <= size + N) {
                capacity *= 2;
            }

            Type *B = new Type[capacity];

            for (int i = 0; i < index; ++i) {
                B[i] = A[i];
            }

            for (int i = 0; i <  N; ++i) {
                B[i+index]=arr[i];
            }

            for (int i = index; i < size; ++i) {
                B[i + N] = A[i];
            }

            delete[] A;
            A = B;
            size += N;
        }
    }


    void Erase(int index, int n) {

        for (int i = index; i < size; ++i) {
            A[i] = A[i + n];
        }
        size -= n;
    }


    int Size() {
        return size;
    }


    int Capacity() {
        return capacity;
    }


    Type &operator[](int index) {
        return A[index];
    }


    friend ostream &operator<<(ostream &os, const MyArray &array) {
        for (int i = 0; i < array.size; ++i) {
            os << array.A[i] << ' ';
        }
        return os;
    }

};


int main() {

    MyArray<int> A;

    int Q;
    cin >> Q;

    string ident;
    for (int i = 0; i < Q; ++i) {
        cin >> ident;

        if (ident == "insert") {
            int index, N;
            cin >> index >> N;

            int arr[N];
            for (int i = 0; i < N; ++i) {
                cin >> arr[i];
            }
            A.Insert(index, arr, N);

        } else if (ident == "erase") {
            int index, n;
            cin >> index >> n;
            A.Erase(index, n);

        } else if (ident == "size") {
            cout << A.Size() << endl;

        } else if (ident == "capacity") {
            cout << A.Capacity() << endl;

        } else if (ident == "get") {
            int index;
            cin >> index;
            cout << A[index] << endl;

        } else if (ident == "set") {
            int index;
            cin >> index;
            cin >> A[index];

        } else if (ident == "print") {
            cout << A << endl;
        }

    }

    return 0;
}
