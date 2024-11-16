#include <iostream>
#include <cstdarg>


void from_to(int k, ...){
    va_list list;
    va_start(list, k);
    for ( ; k>0; k--){
        int answer[24] = {0};
        int n=0, i=0;
        int arg = va_arg(list, int);
        while(arg>0){
            answer[i]=arg%3;
            arg = arg/3;
            n++;
            ++i;
        }
        for(int j=n-1; j>=0; j--){
            std::cout << answer[j] << " ";
        }
        std::cout << "\n";
    }
    va_end(list);
}



int main(){

    from_to(3, 10, 15, 3);
    std::cout << "\n";
    from_to(4, 2, 19, 25, 6);
    std::cout << "\n";
    from_to(7, 66, 17, 8, 1, 13, 27, 22);
    return 0;
}