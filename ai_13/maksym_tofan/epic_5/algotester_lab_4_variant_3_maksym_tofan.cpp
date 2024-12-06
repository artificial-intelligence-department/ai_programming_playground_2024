#include <iostream>
using namespace std;

void merge(int* data, int left, int mid, int right, bool ascending) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftPart = new int[leftSize];
    int* rightPart = new int[rightSize];

    for (int i = 0; i < leftSize; ++i) 
        leftPart[i] = data[left + i];
    for (int j = 0; j < rightSize; ++j) 
        rightPart[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if ((ascending && leftPart[i] <= rightPart[j]) || (!ascending && leftPart[i] >= rightPart[j])) {
            data[k++] = leftPart[i++];
        } else {
            data[k++] = rightPart[j++];
        }
    }

    while (i < leftSize) 
        data[k++] = leftPart[i++];
    while (j < rightSize) 
        data[k++] = rightPart[j++];

    delete[] leftPart;
    delete[] rightPart;
}

void customSort(int* data, int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        customSort(data, left, mid, ascending);
        customSort(data, mid + 1, right, ascending);
        merge(data, left, mid, right, ascending);
    }
}

void addDistinctElements(int* source, int sourceSize, int* target, int& targetSize) {
    for (int i = 0; i < sourceSize; ++i) {
        bool alreadyPresent = false;
        for (int j = 0; j < targetSize; ++j) {
            if (target[j] == source[i]) {
                alreadyPresent = true;
                break;
            }
        }
        if (!alreadyPresent) {
            target[targetSize++] = source[i];
        }
    }
}

int main() {
    int arraySize;
    cin >> arraySize;

    if (arraySize < 1 || arraySize > 1000) {
        cerr << "Помилка: Розмір масиву має бути від 1 до 1000." << endl;
        return 0;
    }

    int* numbers = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        cin >> numbers[i];
        if (numbers[i] < 0 || numbers[i] > 1000) {
            cerr << "Помилка: Елемент має бути у діапазоні від 0 до 1000." << endl;
            delete[] numbers;
            return 0;
        }
    }

    int* divBy3 = new int[arraySize];
    int* mod1 = new int[arraySize];
    int* mod2 = new int[arraySize];
    int sizeDiv3 = 0, sizeMod1 = 0, sizeMod2 = 0;

    for (int i = 0; i < arraySize; ++i) {
        if (numbers[i] % 3 == 0) {
            divBy3[sizeDiv3++] = numbers[i];
        } else if (numbers[i] % 3 == 1) {
            mod1[sizeMod1++] = numbers[i];
        } else {
            mod2[sizeMod2++] = numbers[i];
        }
    }

    customSort(divBy3, 0, sizeDiv3 - 1, true);   // Зростання
    customSort(mod1, 0, sizeMod1 - 1, false);   // Спадання
    customSort(mod2, 0, sizeMod2 - 1, true);    // Зростання

    int* finalArray = new int[arraySize];
    int finalSize = 0;

    addDistinctElements(divBy3, sizeDiv3, finalArray, finalSize);
    addDistinctElements(mod1, sizeMod1, finalArray, finalSize);
    addDistinctElements(mod2, sizeMod2, finalArray, finalSize);

    cout << finalSize << endl;
    for (int i = 0; i < finalSize; ++i) {
        cout << finalArray[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    delete[] divBy3;
    delete[] mod1;
    delete[] mod2;
    delete[] finalArray;

    return 0;
}
