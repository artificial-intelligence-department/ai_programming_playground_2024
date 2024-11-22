#include <iostream>
using namespace std;
int main(){
    int lineQ, columnQ;
    cout << "Введіть через пробіл кількість рядків і стовпців масиву: ";
    cin >> lineQ >> columnQ;
    int arr[lineQ][columnQ];
    for (int i = 0; i < lineQ; i++){
        for(int j = 0; j < columnQ; j++){
            cin >> arr[i][j];
        }
    }
    int leftSum = 0, rightSum = 0;
    for(int i = 1; i < columnQ - 1; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < lineQ; k++){
                leftSum += arr[k][j];
            }
        }
        for(int j = columnQ - 1; j > i; j--){
            for(int k = 0; k < lineQ; k++){
                rightSum += arr[k][j];
            }
        }
        if (leftSum > rightSum){
            cout << "Можна";
            return 0;
        }
        leftSum = 0;
        rightSum = 0;
    }
    cout << "Неможна";
    return 0;
}