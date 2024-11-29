#include <iostream>
#include <string>
using namespace std;

struct DynamicMas {
private:
    int s;
    int capacity;
    int *array;

    void resize(int size) {
        if(size >= capacity) {
            while(size >= capacity)
                capacity *= 2;
            int *newArray = new int[capacity];
            for (int i = 0; i < s; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    DynamicMas() {
        s = 0;
        capacity = 1;
        array = new int[capacity];
    }

    ~DynamicMas() {
        delete[] array;
    }

    int cap() {
        return capacity;
    }

    void insert(int index, int num, int *array2) {
        resize(s+num);

        for (int i = s - 1; i >= index; i--) {
            array[i + num] = array[i];
        }
        for(int i = 0; i < num; i++) {
            array[index + i] = array2[i];
        }

        s += num;
    }

    void erase(int index, int n) {
        for (int i = index; i < s - n; i++) {
            array[i] = array[i + n];  
        }
        s -= n;
    }

    int size() {
        return s;
    }

    int& operator[] (const int index) {
        return array[index];
    }

    int get(int index) {
        return array[index];
    }

    void set(int index, int num) {
        array[index] = num;
    }

    friend ostream& operator<< (ostream &out, const DynamicMas &arr) {
        for(int i = 0; i < arr.s; i++) {
            out << arr.array[i] << " ";
        }
        return out;
    }
    
    void print() {
        cout << *this << "\n";
    }
};

int main() {
    int Q;
    cin >> Q;
    DynamicMas arr;   
    for(int i = 0; i < Q; i++) {
        string com; 
        cin >> com;

        if(com == "size") {
            cout << arr.size() << "\n";
        } else if(com == "capacity") {
            cout << arr.cap() << "\n";
        } else if(com == "print") {
            arr.print();
        } else if(com == "get") {
            int num;
            cin >> num;
            cout << arr.get(num) << "\n";
        } else if(com == "set") {
            int a,b;
            cin >> a >> b;
            arr.set(a, b);
        } else if(com == "erase") {
            int a, b;
            cin >> a >> b;
            arr.erase(a, b);
        } else {
            int a, b;
            cin >> a >> b;
            int *ar = new int[b];
            for(int i = 0; i < b; i++) 
                cin >> ar[i];
            arr.insert(a, b, ar);
            delete[] ar;
            ar = nullptr;
        }
    }
    return 0;
}