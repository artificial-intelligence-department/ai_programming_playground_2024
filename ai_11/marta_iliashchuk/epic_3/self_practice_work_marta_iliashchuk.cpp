#include <iostream>  
#include <stdarg.h>
using namespace std;

// S=a1*a2-a2*a3+a3*a4 

int sum(int numberOfArgs, ...){
    va_list argList;
    va_start(argList, numberOfArgs);

    int value = va_arg(argList, int);
    int sum;
    int result = 0;
    for(int i = 1; i < numberOfArgs; i++){
        int nextValue = va_arg(argList, int);
        sum = value*nextValue;
        if (i%2==0){
            result-=sum;
        }
        else{
            result+=sum;
        }
        value = nextValue;
    }

    va_end(argList);
    return result;

}

int main(){
    cout<<"Sum:"<<sum(5, 5, 7, 4, 8, 1)<<endl;
    cout<<"Sum:"<<sum(10, 5, 7, 4, 8, 2, 3, 55, 77, 6, 54)<<endl;
    cout<<"Sum:"<<sum(12, 5, 7, 4, 8, 2, 3, 55, 77, 6, 54, 5, 1)<<endl;
}
