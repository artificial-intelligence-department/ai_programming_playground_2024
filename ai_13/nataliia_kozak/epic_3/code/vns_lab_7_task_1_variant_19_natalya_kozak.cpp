#include <iostream>
#include <cstdarg>
using namespace std;
int R;
int belong(int n, ...){
        va_list args;
        va_start(args, n);

        int count = 0, x, y;

        for(int i = 0; i < n ; i+=1){
            x = va_arg(args, int);
            y = va_arg(args, int);
            if(x*x + y*y <= R*R){
                count += 1;
            }
        }
        va_end(args);
        return count;

    }

int main(){
    cout << endl << "R = ";
    cin >> R;
    
    cout << belong(1, 2, 2) << endl;
    cout << belong(4, 1, 2, 10, 10, -5, -6, 100, 100) << endl;
    cout << belong(5, 1, 1 -10, -10, 11, 11, 15, 15, -30, -30) << endl;
    return 0;
}

