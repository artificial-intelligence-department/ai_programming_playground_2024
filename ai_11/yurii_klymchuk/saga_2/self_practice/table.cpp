#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Insertion(int arr[], int size){
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    } 
}
int main() {
    int* h = new int[4];
    Insertion(h, 4);

    int* d = new int[4];
    Insertion(d, 4);

    string result;
    for (int i = 0; i < 4; i++){
        h[i] -= d[i];

        if (h[i] < 0){
            result = "ERROR";
        } else if(h[i] * 2 <= *max_element(h, h+4) || h[i] == 0){
            result = "NO";
        }
    }

    if (h[0] == h[1] && h[1] == h[2] && h[2] == h[3] && h[0] > 0){
        result = "YES";
    }
    
    cout << result;
}