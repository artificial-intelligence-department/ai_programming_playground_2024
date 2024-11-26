#include <iostream>

using namespace std;

void push(int* mas1, int& top1, int element1, int n1){
    if(top1 < n1 - 1){
        top1++;
        mas1[top1] = element1;
        for(int i = 0; i <= top1; i++){
            cout << mas1[i] << " ";
        }
    }else{
        cout << "Not enough space!";
    }
}

void destroy(int* mas1, int& top1, int n1){
    if(top1 > -1){
        mas1[top1] = 0;
        top1--;
        for(int i = 0; i <= top1; i++){
            cout << mas1[i] << " ";
        }
    }else{
        cout << "Stack is already emty!";
    }
}

void print(int mas1[], int top1){
    for(int i = 0; i <= top1; i++){
        cout << mas1[i] << " ";
    }    
}

int main(){
    int n;
    int choose = -2;
    cout << "Enter stack size: ";
    cin >> n;
    int mas[n];
    int top = -1;
    int element;
    do{
        cout << endl << "Choose an option: add(1), destroy(0), print(2) or exit(-1): ";
        cin >> choose;
        if(choose == 1){
            cout << "Enter an element: ";
            cin>>element;
            push(mas, top, element, n);
        }
        if(choose == 0){
            destroy(mas, top, n);
        }
        if(choose == 2){
            print(mas, top);
        }
    } while (choose != -1);
    return 0;
}