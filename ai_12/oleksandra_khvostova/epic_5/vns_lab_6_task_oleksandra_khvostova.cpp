#include <iostream>
#include <cstring> // Для strtok
#include <algorithm> // Для sort

using namespace std;

int main() {
    char str[255];
    cout << "Enter a string of numbers separated by spaces: ";
    gets(str); 

    char* token = strtok(str, " ");
    int numbers[255];
    int count = 0;

    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    sort(numbers, numbers+count);

    cout << "Sorted numbers: ";
    for (int i = count-1; i >=0; i--) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    delete[]token;

    return 0;
}