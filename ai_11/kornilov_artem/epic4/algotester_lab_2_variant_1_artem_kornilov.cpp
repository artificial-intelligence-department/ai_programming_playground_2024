#include <iostream>

using namespace std;

int main () {

    struct Data
    {
    int arrSz;
    int maxValue;
    int minValue;
    int maxValue2;
    int minValue2;
    };

    Data d1;

    cin >> d1.arrSz;

    if (d1.arrSz > 100000 || d1.arrSz < 1){
        return 0;
    }

    int* arr = new int[d1.arrSz];

    for (int i = 0; i < d1.arrSz; i++){
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 100000) {
            return 0;
        }
    }

    d1.maxValue = -1;
    d1.minValue = 100001;
    d1.maxValue2 = 0;
    d1.minValue2 = 100000;
    bool minOnce = true;
    bool maxOnce = true;

    for (int i = 0; i < d1.arrSz; i++) {

        if (d1.minValue == arr[i]) {
            minOnce = false;
        }

        if (d1.maxValue == arr[i]) {
            maxOnce = false;
        }
        
        if (d1.maxValue < arr[i]) {
            d1.maxValue = arr[i];
            maxOnce = true;
        }

        if (d1.minValue > arr[i]) {
            d1.minValue = arr[i];
            minOnce = true;
        }

    }

    for (int i = 0; i < d1.arrSz; i++) {

        if (arr[i] > d1.maxValue2 && arr[i] < d1.maxValue) {
            d1.maxValue2 = arr[i];
        }

        if (arr[i] < d1.minValue2 && arr[i] > d1.minValue) {
            d1.minValue2 = arr[i];
        }
       
    }

    unsigned int result = d1.maxValue - d1.minValue;
    
    if (d1.maxValue - d1.minValue2 < result && minOnce) {
        result = d1.maxValue - d1.minValue2;
    }

    if (d1.maxValue2 - d1.minValue < result && maxOnce) {
        result = d1.maxValue2 - d1.minValue;
    } 

    delete[] arr;

    arr = nullptr;

    cout << result;

    return 0;
}