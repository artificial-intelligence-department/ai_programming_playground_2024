#include <iostream>
using namespace std;

void Transposition(int matrix[3][3]) {
    cout << "Matrix transposition:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

void Symetric(int matrix[3][3]) {
    int count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(matrix[i][j] == matrix[j][i]){
                count += 1;
            }
        }
    }
    if(count == 9) {
        cout << "Symetric";
    } else {
        cout << "Not symetric";
    }
}

int main() {

    int matrix[3][3] = {};
    int num;
    for(int i = 0; i < 3; i++) {
        cout << "Input row " << i + 1 << endl;
        for(int j = 0; j < 3; j++) {
            cin >> num;
            matrix[i][j] = num;
        }
    }

    cout << "Matrix:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Transposition(matrix);
    Symetric(matrix);


    return 0;
}