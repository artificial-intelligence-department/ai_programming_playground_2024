#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countElements(const vector<int>& numbers) {
    int count = 0;
    for (int number : numbers) {
        if (number % 2 == 0) {
            count++;
        }
    }
    return count;
}
int countElements(const string& text) {
    int count = 0;
    size_t start = 0;
    size_t length = text.size();

    while (start < length) {
        while (start < length && text[start] == ' ') {
            start++;
        }
        size_t end = start;
        while (end < length && text[end] != ' ') {
            end++;
        }

        if (end > start && (text[start] == 'a' || text[start] == 'A')) {
            count++;
        }

        start = end + 1;
    }

    return count;
}
int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Number of even elements: " << countElements(numbers) << endl;
    string text = "apple army marble avocado action mystery";
    cout << "Number of words starting with 'a': " << countElements(text) << endl;
    return 0;
}
