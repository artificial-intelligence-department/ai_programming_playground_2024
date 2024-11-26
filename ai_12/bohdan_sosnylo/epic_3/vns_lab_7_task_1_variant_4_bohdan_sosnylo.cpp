#include <iostream>
#include <cstdarg>
using namespace std;


//4. Написати функцію sum зі змінною кількістю параметрів, що знаходить суму
//чисел типу int за формулою:
//S=a1*a2+a3*a4+a5*a6+. . . . .

int sum(int count, ...){
    int h = 1,sum = 0;
    va_list args;
    va_start(args, count);

    for(int i = 1;i<=count ;i++){
        int p = va_arg(args,int);
            if( (i+1) % 2 == 0){
                h *= p;
            }
            if( i % 2 == 0){
                h *= p;
                sum+=h;
                h = 1;
        }
    }
    va_end(args);
    return(sum);
}
              
int main(){

cout <<sum(3,8,9,10)<<endl;
cout <<sum(5,12,15,13,18,20)<<endl;
cout <<sum(10,1,2,3,4,5,6,7,8,9,10)<<endl;

    return 0;
}



