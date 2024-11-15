#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Функція для видалення всіх парних елементів з масиву цілих чисел
void remove_even_elements(vector<int>& arr) {
    vector<int> result;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {
            result.push_back(arr[i]);
        }
    }
    arr = result;
}

// Функція для видалення всіх парних слів з рядка
void remove_even_elements(string& text) {
    istringstream iss(text);
    string word;
    string result;
    int word_count = 1;
    while (iss >> word) {
        if (word_count % 2 != 0) { 
            result += word + " ";
        }
        word_count++;
    }
    text = result;
}

int main() {

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Масив до видалення парних елементів: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    remove_even_elements(numbers);

    cout << "Масив після видалення парних елементів: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    string text = "це приклад рядка для видалення парних слів";
    cout << "Рядок до видалення парних слів: " << text << endl;

    remove_even_elements(text);

    cout << "Рядок після видалення парних слів: " << text << endl;

    return 0;
}
