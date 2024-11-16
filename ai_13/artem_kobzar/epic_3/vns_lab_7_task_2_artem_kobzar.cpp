#include <iostream>

using namespace std;

int initial_func(int n, int arr[]) {
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int initial_func(const string& str) {
    int maxLength = 0, currentLength = 0;

    for (char ch : str) {
        if (ch != ' ') {
            currentLength++;
        } else { 
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength;
}

int main() {
    int n;
    cout << "Enter the amount of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter all elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_value = initial_func(n, arr);
    cout << "Maximum value in array: " << max_value << endl;

       cin.ignore();  // Очищення буфера перед введенням рядка
    string text;
    cout << "Enter a string: ";
    getline(cin, text);
    int max_word_length = initial_func(text);
    cout << "Length of the longest word in the string: " << max_word_length << endl;

    return 0;
}