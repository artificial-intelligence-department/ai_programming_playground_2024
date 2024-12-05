#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T *arr;
    int size;
    int capacity;

public:
    // Конструктор
    DynamicArray() {
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }
    // Деструктор
    ~DynamicArray() {
        delete[] arr;
    }
    // Вставка елементів
    void insert(int index, int amount, T *toInsert) {
        while (size + amount >= capacity) {
            capacity *= 2;
        }
        T *temp = new T[capacity];
        for (int i = 0; i < index; i++) {
            temp[i] = arr[i];
        }
        for (int i = 0; i < amount; i++) {
            temp[index + i] = toInsert[i];
        }
        for (int i = index; i < size; i++) {
            temp[i + amount] = arr[i];
        }
        size += amount;
        delete[] arr;
        arr = temp;
    }
    // Видалення елементів
    void erase(int index, int amount) {
        T *temp = new T[capacity];
        int acc = 0;

        for (int i = 0; i < size; i++) {
            if (i < index || i >= index + amount) {
                temp[acc] = arr[i];
                acc++;
            }
        }

        size -= amount;
        delete[] arr;
        arr = temp;
    }
    // Отримання елемента
    T get(int index) const {
        return arr[index];
    }
    // Встановлення значення елемента
    void set(int index, T value) {
        arr[index] = value;
    }
    // Отримання розміру масиву
    int getSize() const {
        return size;
    }
    // Отримання ємності масиву
    int getCapacity() const {
        return capacity;
    }
    // Виведення масиву
    void print(const string &separator) const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << separator;
        }
        cout << endl;
    }
};

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
            arr.insert(index, N, temp);
            delete[] temp;
        } else if (line == "erase") {
            int index, N;
            cin >> index >> N;
            arr.erase(index, N);
        } else if (line == "size") {
            cout << arr.getSize() << endl;
        } else if (line == "capacity") {
            cout << arr.getCapacity() << endl;
        } else if (line == "get") {
            int i;
            cin >> i;
            cout << arr.get(i) << endl;
        } else if (line == "set") {
            int i, value;
            cin >> i >> value;
            arr.set(i, value);
        } else if (line == "print") {
            arr.print(" ");
        }
    }

    return 0;
}