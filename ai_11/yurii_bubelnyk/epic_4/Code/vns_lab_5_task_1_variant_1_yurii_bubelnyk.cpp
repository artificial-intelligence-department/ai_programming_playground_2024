#include <iostream>
#include <cstring>
using namespace std;

const int MaxSize = 255;

void Show(char arr[][MaxSize], int col, int length[]);

int main() {
    char arr[MaxSize][MaxSize];
    int lengths[MaxSize];
    int col = 0;

    cout << "How many words you want to add? (max " << MaxSize << "): " << endl;
    cin >> col;

    // Перевірка на допустиму кількість слів
    if (col > MaxSize) {
        cout << "You can enter a maximum of " << MaxSize << " words." << endl;
        return 1;
    }

    cin.ignore();

    for (int i = 0; i < col; i++) {
        cout << "Enter number of the " << i + 1 << " word: ";
        cin.getline(arr[i], MaxSize);  
        lengths[i] = strlen(arr[i]);  // Підрахунок довжини слова
    }

    Show(arr, col, lengths);  

    return 0;
}

void Show(char arr[][MaxSize], int col, int length[]) {
    for (int i = 0; i < col; i++) {
        cout << "(";
        for (int j = 0; j < length[i]; j++) {
            if(arr[i][j+1] == '\0'){
                break;
            }
            if (arr[i][j] == '0') {
                    cout << ","; 
            } else {
                cout << arr[i][j]; 
            }
        }
        cout << ")";
    }

    cout << endl;
}
