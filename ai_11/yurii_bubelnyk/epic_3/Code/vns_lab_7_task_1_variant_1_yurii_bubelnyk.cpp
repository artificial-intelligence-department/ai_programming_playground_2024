#include <iostream>
#include <cstdarg>
using namespace std;

int Sum(int count, ...);

int main(){

    cout << "Sum of 3 numbers: " << Sum(3, 1, 2, 3) << endl;
    cout << "Sum of 7 numbers: " << Sum(7, 1, 2, 3, 4, 5, 6, 7) << endl;
    cout << "Sum of 11 numbers: " << Sum(11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11) << endl;

    return 0;
}

int Sum(int count, ...){
    int sum = 0;

    va_list list;
    va_start(list,count);

    for(int arg = 0; arg < count; arg++){
        
        sum += va_arg(list, int);

    }

    va_end(list);
    return sum;
}
