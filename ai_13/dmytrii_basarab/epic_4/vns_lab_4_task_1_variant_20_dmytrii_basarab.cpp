#include <iostream>
#include <vector>
using namespace std;
 
// Функція для роздрукування елементів кільця від певного індексу вправо
void printRight(vector<int>& vec, int n, int k) {
    cout << "Перегляд вправо з індексу " << k << ": ";
    for (int i = k; ; ) {
        cout << vec[i] << " ";
        i = (i + 1) % n;  // Перехід вправо, циклічно від k до k
        // 0 1 2 3 4   при і = 2 і n = 5 3/5 = 0 остача 3 
        //отже і стає 3 - наступним елементом
        if (i == k) break; // Повертаємося до початкового індексу
    }
    cout << endl;
}

void insertZeros(vector<int>& vec) {
    int i;
    cout << "Нулі біля кратних 5: " << vec[i] << " ";
    for (i = 0; i < vec.size(); ++i) {
        if (i % 5 == 0) {//після елементів кратних 5 тому +1
            vec.insert(vec.begin() + i + 1, 0);
            i++;//пропускаєм доданий елемент
        }
    cout << vec[i] << " ";
    }
    cout << endl;
}

// Функція для роздрукування елементів кільця від певного індексу вліво
void printLeft(vector<int>& vec, int n, int k) {
    cout << "Перегляд вліво з індексу " << k << ": ";
    for (int i = k; ; ) {
        cout << vec[i] << " ";
        i = (i - 1 + n) % n;  // Перехід вліво, циклічно, додаєм n щоб індекс не став відємним він переміщається  в останній елемент
        if (i == k) break; // Повертаємося до початкового індексу
    }
    cout << endl;
}

int main() {



    vector<int> vec;
    int n;
    cout << "Розмір масиву: ";
    cin >> n;
    cout << "Елементи: ";
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        vec.push_back(q);
    }


  

    int k;
    cout << "Введіть початковий індекс для перегляду (від 0 до " << n-1 << "): ";
    cin >> k;

 
    printRight(vec, n, k);
    insertZeros(vec);
    printLeft(vec, n, k);

 
    return 0;
}