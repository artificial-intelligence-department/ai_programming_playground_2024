#include <iostream>
#include <vector>
#include <string>

using namespace std;

void remove(vector<int>& vec) {
    vector<int> result;
    for (int x : vec) {
        if (x % 2 != 0) {
            result.push_back(x);
        }
    }
    vec = result;
}

void remove(vector<string>& vec) {
    vector<string> result;
    for (int i = 0; i < vec.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(vec[i]);
        }
    }
    vec = result;
}

int main() {
    int size_n;
    cout << "Введіть кількість елементів: " << endl;
    cin >> size_n;

    vector<int> numbers(size_n);
    cout << "Введіть " << size_n << " чисел: " << endl;
    for (int i = 0; i < size_n; i++) {
        cin >> numbers[i];
    }
    
    remove(numbers);
    cout << "Результат видалення парних чисел: " << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    int size_w;
    cout << "Введіть кількість слів: " << endl;
    cin >> size_w;
    cin.ignore();
    
    vector<string> words(size_w);
    cout << "Введіть " << size_w << " слів: " << endl;
    for (int i = 0; i < size_w; i++) {
        getline(cin, words[i]);
    }

    remove(words);
    cout << "Результат видалення слів з непарними індексами: " << endl;
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
