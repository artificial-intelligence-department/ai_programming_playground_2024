#include <iostream>
#include <string>

using namespace std;

void sort(string* names, int n) {
    for (int start = 0; start < n - 1; start++) {
        int small = start;
        for (int current = start + 1; current < n; current++) {
            if (names[current] < names[small]) {
                small = current;
            }
        }
        swap(names[start], names[small]);
    }
}

int main() {
    cout << "Скільки імен ви хочете ввести?" << endl;
    int n;
    cin >> n;
    string* names = new string[n];
    
    cout << "Введіть імена:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    sort(names, n);

    cout << "Відсортований список імен:" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    delete[] names;

    return 0;
}
