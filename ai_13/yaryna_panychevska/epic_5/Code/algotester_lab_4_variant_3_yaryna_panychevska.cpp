#include <iostream>
#include <vector>
using namespace std;

// Функція для поділу (Partition)
int partition(vector<int>& arr, int low, int high, bool ascending = true) {
    int pivot = arr[high]; // Вибираємо опорний елемент (останній елемент)
    int i = low - 1;       // Індекс меншого елемента

    for (int j = low; j < high; j++) {
        // Якщо елемент менший/більший за опорний залежно від порядку
        if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Переміщуємо опорний елемент на його правильне місце
    return i + 1;               // Повертаємо індекс опорного елемента
}

// Функція Quick Sort
void quickSort(vector<int>& arr, int low, int high, bool ascending = true) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending); // Розділяємо масив
        quickSort(arr, low, pi - 1, ascending);        // Сортуємо ліву частину
        quickSort(arr, pi + 1, high, ascending);       // Сортуємо праву частину
    }
}

// Функція для видалення дублікатів
void remove_duplicates(vector<int>& vec) {
    int n = vec.size();
    if (n == 0) return;

    int index = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] != vec[index]) {
            index++;
            vec[index] = vec[i];
        }
    }
    vec.resize(index + 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Розподіл на категорії
    vector<int> vec0, vec1, vec2;
    for (int i = 0; i < n; i++) {
        if (vec[i] % 3 == 0) {
            vec0.push_back(vec[i]);
        } else if (vec[i] % 3 == 1) {
            vec1.push_back(vec[i]);
        } else {
            vec2.push_back(vec[i]); // Додаємо елементи з остачею 2
        }
    }

    // Сортування груп
    quickSort(vec0, 0, vec0.size() - 1, true);   // Сортування за зростанням
    quickSort(vec1, 0, vec1.size() - 1, false); // Сортування за спаданням
    quickSort(vec2, 0, vec2.size() - 1, true);  // Сортування за зростанням

    // Об'єднання масивів
    vector<int> merged;
    merged.insert(merged.end(), vec0.begin(), vec0.end());
    merged.insert(merged.end(), vec1.begin(), vec1.end());
    merged.insert(merged.end(), vec2.begin(), vec2.end());

    remove_duplicates(merged);
   
    
    // Виведення результату
    cout << merged.size() << "\n";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

