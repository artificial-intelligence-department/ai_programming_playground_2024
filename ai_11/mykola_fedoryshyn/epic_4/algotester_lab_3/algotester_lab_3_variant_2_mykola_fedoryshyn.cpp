#include "iostream"
#include "string"
#include "cmath"
using namespace std;

int main(){
    int size1, size2, n;

    cin >> size1;
    int list1[size1];
    for(int i = 0; i < size1; i++){
        cin >> list1[i];
    }
    cin >> size2;
    int list2[size2];
    for(int i = 0; i < size2; i++){
        cin >> list2[i];
    }

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(list1[i] == list2[j]){
                n++;
            }
        }
    }
    cout << n << endl << size1+size2 - n;
    return 0;
}