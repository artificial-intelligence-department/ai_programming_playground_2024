#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int func(int arr[], int len){
    int max = arr[0];

    for(int i = 1; i < len; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int func(string str){
    stringstream strStream(str);
    string word;
    int max = 0;
    
    while (strStream >> word) {
        if (word.length() > max) {
            max = word.length();
        }
    }
    
    return max;
}

int main(){
    int arr[] = {1, 5 , 10 , 4, 15};
    int len = sizeof(arr) / sizeof(arr[0]);
    string str = "Hello I am Stefan";

    cout << "Максимальний елемент у масиві: " << func(arr, len) << endl;

    cout << "Довжина найдовшого слова: " << func(str) << endl;
}