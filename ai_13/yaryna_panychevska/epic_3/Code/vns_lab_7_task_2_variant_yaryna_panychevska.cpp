#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void Print(int num[], int size_num) {
    int negativeCount = 0; 
    for (int i = 0; i < size_num; i++) {
        if (num[i] < 0) {
            negativeCount++; 
        }
    }
    cout << "Number of negative numbers: " << negativeCount << endl;
}

void Print(const string& str) {
    istringstream stream(str);
    string word;
    int count = 0;

    while (stream >> word) {
        count++;
    }

    cout << "Number of words: " << count << endl;
}
int main() {
    int num[] = { -1, 4, 5, -9, -8, 10, 3, 6, 0, 11 };
    int size_num = sizeof(num) / sizeof(num[0]);
    Print(num, size_num);

    string words = "Today is my birthday! Now I am 18 years old.";
    Print(words);

    return 0;
}
