#include <iostream>
#include <string>
#include <cctype>

using namespace std;


double calculate(int array[], int size){
    int sum;
    if(size == 0){
        return 0;
    }

    for(int i = 0; i < size; i++){
       sum += array[i]; 
    }
    return  sum/size;
}


int calculate(const string &symbols) {
    int counter = 0;
    for (char ch : symbols) {
        if (isalpha(ch)) {  // Перевіряє, чи символ є літерою
            ++counter;
        }
    }
    return counter;
}


int main(){

    int size;
    cout << "Enter size of mass: ";
    cin >> size;
    int array[size];
    for(int i = 0; i < size; i++){
        cout << "Num" << i+1 << ": ";
        cin >> array[i];
    }
    double average = calculate(array, size);
    cout << average << endl;


    string symbols; 
    cout << "Warning! Only one word, or phrase without space between words" << endl;
    cout << "Enter symbols: ";
    cin >> symbols;

    int letters = calculate(symbols);
    cout << letters << endl;

    return 0;
}
