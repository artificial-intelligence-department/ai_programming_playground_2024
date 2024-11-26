#include <iostream>
#include <stdarg.h>
using namespace std;

int min(int numberOfArgs, ...){
    va_list argList;
    va_start(argList, numberOfArgs);

    int minValue = va_arg(argList, int);

    for(int i = 1; i<numberOfArgs; i++){
        int value = va_arg(argList, int);
        if (minValue>value){
            minValue = value;
        }
    }
    va_end(argList);

    return minValue;
}

int main(){
    cout<<"Найменше значення:"<<min(5, 5, 7, 4, 8, 1)<<endl;
    cout<<"Найменше значення:"<<min(10, 5, 7, 4, 8, 2, 3, 55, 77, 6, 54)<<endl;
    cout<<"Найменше значення:"<<min(12, 5, 7, 4, 8, 2, 3, 55, 77, 6, 54, 0, 1)<<endl;
}