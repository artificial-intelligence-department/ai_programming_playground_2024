#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для знаходження різниці A - B
vector<int> difference(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    for (int a : A) {
        if (find(B.begin(), B.end(), a) == B.end()) { // Якщо a не в B
            result.push_back(a);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Функція для знаходження перетину A ∩ B
vector<int> intersection(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    for (int a : A) {
        if (find(B.begin(), B.end(), a) != B.end()) { // Якщо a є в B
            if (find(result.begin(), result.end(), a) == result.end()) { // Уникнення дублювань
                result.push_back(a);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Функція для об'єднання A ∪ B
vector<int> unionSet(const vector<int>& A, const vector<int>& B) {
    vector<int> result = A; // Починаємо з усіх елементів A
    for (int b : B) {
        if (find(A.begin(), A.end(), b) == A.end()) { // Якщо b не в A
            result.push_back(b);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Функція для знаходження симетричної різниці A Δ B
vector<int> symmetricDifference(const vector<int>& A, const vector<int>& B) {
    vector<int> diff1 = difference(A, B); // A - B
    vector<int> diff2 = difference(B, A); // B - A
    vector<int> result = diff1;
    result.insert(result.end(), diff2.begin(), diff2.end()); // Поєднуємо A - B і B - A
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end()); // Видаляємо дублікати
    return result;
}

// Функція для друку результату
void printVector(const vector<int>& v) {
    cout << v.size() << "\n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int N, M;

    // Зчитуємо розмір і елементи першого масиву
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }

    // Зчитуємо розмір і елементи другого масиву
    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; ++i) {
        cin >> array2[i];
    }

    // Обчислення множинних операцій
    vector<int> diff1 = difference(array1, array2);          // Різниця N - M
    vector<int> diff2 = difference(array2, array1);          // Різниця M - N
    vector<int> inter = intersection(array1, array2);        // Перетин
    vector<int> uni = unionSet(array1, array2);              // Об’єднання
    vector<int> symDiff = symmetricDifference(array1, array2); // Симетрична різниця

    // Виведення результатів
    printVector(diff1); // Різниця N - M
    printVector(diff2); // Різниця M - N
    printVector(inter); // Перетин
    printVector(uni);   // Об’єднання
    printVector(symDiff); // Симетрична різниця

    return 0;
}
