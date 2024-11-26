#include <iostream>
#include <vector>
#include <string>   //функція стандартних вбудованих бібліотек як завдання

using namespace std;


static void findEvenNumbers(const vector<int>& arr, int index) { 
    if (index >= arr.size()) {
        return;
    } // для виходу з функції після рекурсій коли індекс більший за кількість елементів


    if (arr[index] % 2 == 0) {
        cout << arr[index] << " ";
    } //сама умова парності


    findEvenNumbers(arr, index + 1); //додає індекс
}


void findEvenNumbers(int arr2[], int size) {
    if (size <= 0) {
        return;
    }


    if (arr2[size - 1] % 2 == 0) {
        cout << arr2[size - 1] << " ";
    }


    findEvenNumbers(arr2, size - 1);
}



void finda(char s[],int sym) {
    cout << "\n Пошук слів на а через масив char:\n";
            int l = 0;
            int k;
        if ( s[0] == 'a' ) {
            while (s[l] != ' ') {
                cout << s[l];
                k++;
                l++;
            }
        }
    cout << " ";
    for ( k = 0; k < sym; k++) {

                       
        if ( s[k] == 'a' && s[k-1] == ' ') {
            while (s[k] != ' ') {
                cout << s[k];
                k++;
            }cout << " ";
        }
        
    }
}

    void finda(string str,int length) {
        cout << "\n Пошук слів на а через str:\n";
            int q =0;
            int r;
        if ( str[0] == 'a') {
            while (str[q] != ' ') {
                cout << str[q];
                q++;
                r++;
            }
        }
    cout << " ";
    for ( r = 0; r < length; r++) {

                       
        if ( str[r] == 'a' && str[r-1] == ' ') {
            while (str[r] != ' ') {
                cout << str[r];
                r++;
            }cout << " ";
        }
        
    }
    }


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        cout << " Парні числа, знайдені через індекс:\n";
        findEvenNumbers(arr, 0);  // Виклик першої функції з індексом до вектора

        cout << "\n Парні числа, знайдені через розмір:\n";
        findEvenNumbers(arr2, 8);  // Виклик другої функції з розміром масиву


    char s[] = "award after green and far \0";
    int sym = sizeof(s) / sizeof(s[0]); // n байт з кожного символу / на 1 байт розмір 1 символа = їх к-ть 

    string str = "award after green and far \0";
    int length = str.length();

        finda(s, sym);

        finda(str, length);

    return 0;
}
