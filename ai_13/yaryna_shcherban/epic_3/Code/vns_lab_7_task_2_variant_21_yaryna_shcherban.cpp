#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int findNegative (const vector<int>& array) {
    int count = 0;
    for (int num : array) {
        if (num < 0) {
            count++;
        }
    }
    return count; 
}

int findWord(const string& str) {
    int count = 0;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        char first = tolower(word.front());
        char last = tolower(word.back());

        if (first == last) {
            count++;
        }
    }
    return count;
}

int main() {

    vector<int> numbers;
    int n;                                                                            
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter elements for array : ";    
    for (int i = 0; i < n; i++) {
        int Number;
        cin >> Number;
        numbers.push_back(Number);
    }
    cout << "Number of negative elements in the array :" << findNegative (numbers) << endl;


    string sentence ;
    cout << "Enter the sentence: ";
    cin >> sentence;
    cout << "Number of words beginning and ending with the same letter :" << findWord(sentence) << endl;

    return 0;
}