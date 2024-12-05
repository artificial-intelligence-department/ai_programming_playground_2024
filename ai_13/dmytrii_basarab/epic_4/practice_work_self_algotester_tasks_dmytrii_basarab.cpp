#include <iostream>

using namespace std;

int main() {
    int common = 0;
    int unique = 0;

    struct dynamic {
        int M;
    } forarr1, forarr2;

    cin >> forarr1.M;
    int* arr1 = new int[forarr1.M];
    for (int i=0;i<forarr1.M;i++) {
        cin >> arr1[i];
    }

    cin >>forarr2.M;
    int* arr2 = new int[forarr2.M];
        for (int j=0;j<forarr2.M;j++) {
        cin >> arr2[j];
    }    

    for (int k = 0; k < forarr1.M; k++){
        for (int q = 0; q < forarr2.M; q++){
            if (arr1[k]==arr2[q]) {
                common++;
            }
        }
    }
    
    unique = forarr1.M+forarr2.M-common;
    cout << common << endl;
    cout << unique << endl;
    delete[] arr1;
    delete[] arr2;
    return 0;
}