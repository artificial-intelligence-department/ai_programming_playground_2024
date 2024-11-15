#include <iostream>
#include <string>
#include <cctype> // для isalpha
using namespace std;


double Average(int m[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += m[i];}
    return static_cast<double>(sum) / size;}


int Letters(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (isalpha(ch)) {
            ++count;}}
    return count;}


int main() {
    int size;
    cout << "Введіть кількість чисел: ";
    cin >> size;
    
    int* numbers = new int[size]; // вказівник - адреса до змінної numbers
    cout << "Введіть числа: ";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];}
    double average_num = Average(numbers, size);
    cout << "Середнє арифметичне: " << average_num << endl;
    delete[] numbers; 
    
    cin.ignore(); 


    string text;
    cout << "Введіть текст: ";
    getline(cin, text);
    int letters_num = Letters(text);
    cout << "Кількість літер: " << letters_num << endl;
    return 0;}