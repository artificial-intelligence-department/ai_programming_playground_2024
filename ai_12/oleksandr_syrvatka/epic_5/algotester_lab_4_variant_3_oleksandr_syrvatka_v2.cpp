#include <iostream>
#include <vector>

using namespace std;

// Об'єднана функція для сортування злиттям
void mergeSort(vector<int>& vec, int left, int right, bool ascending) {
    if (left >= right) return;  // Базовий випадок

    int mid = left + (right - left) / 2;
    
    // Рекурсивне сортування лівої та правої частин
    mergeSort(vec, left, mid, ascending);
    mergeSort(vec, mid + 1, right, ascending);

    // Об'єднання відсортованих підмасивів
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

// Функція для видалення дублікатів з масиву
void removeDuplicates(vector<int>& vec) {
    vector<int> uniquearr;
    for (int i = 0; i < vec.size(); ++i) {
        if (i == 0 || vec[i] != vec[i - 1]) {
            uniquearr.push_back(vec[i]);
        }
    }
    vec = uniquearr;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділяємо масив на три частини за остачею від ділення на 3
    vector<int> mod0, mod1, mod2;
    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }

    // Сортуємо відповідно до умов
    mergeSort(mod0, 0, mod0.size() - 1, true);   // За зростанням
    mergeSort(mod1, 0, mod1.size() - 1, false);  // За спаданням
    mergeSort(mod2, 0, mod2.size() - 1, true);   // За зростанням

    // Об'єднуємо три масиви
    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    // Видаляємо дублікати
    removeDuplicates(result);

    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
