#include <iostream>
#include <set>

using namespace std;

//використовую структуру для зберігання масивів і їх розміру
struct ArrayData {
    int* array; //використовую динамічний масив
    int size;
};

//використовую вкладену структуру для зберігання результатів обробки
struct Results {
    int** matrix;     //використовую матрицю для порівняння (ДВОМІРНИЙ МАСИВ)
    int intersectionCount;
    int unionCount;
};

//використовую посилання для передачі структури та уникнення копіювання
int findIntersection(const ArrayData& a, const ArrayData& b, Results& res) {
    int count = 0;
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < b.size; ++j) {
            if (a.array[i] == b.array[j]) {
                res.matrix[i][j] = 1;
                ++count;
            } else {
                res.matrix[i][j] = 0;
            }
        }
    }
    return count;
}

//використовую множини для зберігання унікальних елементів (СТРУКТУРИ ДАНИХ)
int findUnion(const ArrayData& a, const ArrayData& b) {
    set<int> uniqueElements; //використовую множину для автоматичного видалення повторень
    for (int i = 0; i < a.size; ++i) {
        uniqueElements.insert(a.array[i]);
    }
    for (int i = 0; i < b.size; ++i) {
        uniqueElements.insert(b.array[i]);
    }
    return uniqueElements.size();
}

int main() {
    ArrayData a; //використовую структуру для зберігання масиву
    cin >> a.size;
    a.array = new int[a.size]; //використовую динамічний масив для зберігання елементів
    for (int i = 0; i < a.size; ++i) {
        cin >> a.array[i];
    }

    ArrayData b; //використовую структуру для зберігання масиву
    cin >> b.size;
    b.array = new int[b.size]; //використовую динамічний масив для зберігання елементів
    for (int i = 0; i < b.size; ++i) {
        cin >> b.array[i];
    }

    Results res; //використовую вкладену структуру
    res.matrix = new int*[a.size]; //використовую динамічний двомірниц масив
        for (int i = 0; i < a.size; ++i) {
        res.matrix[i] = new int[b.size];
    }

    res.intersectionCount = findIntersection(a, b, res); //використовую алгоритм обробки при пошуку спільних елементів
    res.unionCount = findUnion(a, b); //використовую алгоритм обробки при пошуку унікальних елементів

    cout << res.intersectionCount << endl;
    cout << res.unionCount << endl;

    delete[] a.array;
    delete[] b.array;
    for (int i = 0; i < a.size; ++i) {
        delete[] res.matrix[i];
    }
    delete[] res.matrix;

    return 0;
}
