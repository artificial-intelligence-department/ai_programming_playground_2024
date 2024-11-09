#include <iostream>
using namespace std;

int minimum(int a[], int size){
    int min = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}
int minimum(string a){
    int l = a.length();
    int min = l, count = 0;
    for(char c : a){
        if(c != ' '){
            count += 1;
        }
        else{
            if(count < min) {
                min = count;
            }
            count = 0;
        }
    }
    return min;
}
int main(){
    int array[] = {10,5,6,2,3};
    cout << endl << minimum(array, 5);
    string str = "Natalya wrote four words";
    cout << endl << minimum(str);
    return 0;

}