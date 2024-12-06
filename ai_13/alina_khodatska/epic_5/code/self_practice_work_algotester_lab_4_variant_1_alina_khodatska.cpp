#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSet(const vector<int>& result) { // функція для виведення масиву
    cout << result.size() << endl;
	for (int num : result) { // цикл для виведення чисел масиву
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int N, M;

    // Вхідні дані
    cin >> N;
	vector<int> set1(N); // Масив чисел розміром N для зберігання введених чисел
	for (int i = 0; i < N; ++i) { // цикл для введення чисел масиву
        cin >> set1[i];
    }

    cin >> M;
	vector<int> set2(M); // Масив чисел розміром M для зберігання введених чисел
	for (int i = 0; i < M; ++i) { // цикл для введення чисел масиву
        cin >> set2[i];
    }

    // Сортуємо масиви
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    // Різниця N-M
    vector<int> diff1;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(diff1));
    printSet(diff1);

    // Різниця M-N
    vector<int> diff2;
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), back_inserter(diff2));
    printSet(diff2);

    // Перетин
    vector<int> inter;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(inter));
    printSet(inter);

    // Об'єднання
    vector<int> uni;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(uni));
    printSet(uni);

    // Симетрична різниця
    vector<int> symDiff;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(symDiff));
    printSet(symDiff);

    return 0;
}
