#include <iostream>
#include <string>
#include <sstream> 
#include <cctype>
using namespace std;

int countElements(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] % 2 == 0) ++count;
    return count;
}

int countElements(const string& str) {
    int count = 0;
    string word;
    istringstream stream(str);
    while (stream >> word)
        if (tolower(word[0]) == 'a') ++count;
    return count;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6};
    cout << "Even numbers: " << countElements(numbers, 6) << endl;

    string sentence;
    cout << " Enter a sentense : ";
    getline(cin, sentence);
    cout << " Number of words starting with the letter a : " << countElements(sentence) << endl;

    return 0;
}
