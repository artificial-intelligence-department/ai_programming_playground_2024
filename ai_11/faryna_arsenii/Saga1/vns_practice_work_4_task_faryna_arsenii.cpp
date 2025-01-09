#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main (){

    srand(static_cast<unsigned int> (time(nullptr)));

    const int SIZE = 10;
    int arr1[SIZE], arr2[SIZE], arr3[SIZE];

    for (int i = 0; i < SIZE; i++){
        arr1[i] = rand() % 10;
        arr2[i] = rand() % 10;
        arr3[i] = rand() % 10; 
    }

    cout << "Sequence1: "; 
    for (int i = 0; i < SIZE; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Sequence2: "; 
    for (int i = 0; i < SIZE; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Sequence3: "; 
    for (int i = 0; i < SIZE; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    double sum1, sum2, sum3;

    for (int i = 0; i < SIZE; i++){
        sum1 += arr1[i];
        sum2 += arr2[i];
        sum3 += arr3[i]; 
    }

    cout << "Sum1: " << sum1 << endl;
    cout << "Sum2: " << sum2 << endl;
    cout << "Sum3: " << sum3 << endl;

    double middle_value1 = sum1 / SIZE;
    double middle_value2 = sum2 / SIZE;
    double middle_value3 = sum3 / SIZE;

    cout << fixed << setprecision(2);
    cout << "Average1: " << middle_value1 << endl;
    cout << "Average2: " << middle_value2 << endl;
    cout << "Average3: " << middle_value3 << endl;

    return 0;
}