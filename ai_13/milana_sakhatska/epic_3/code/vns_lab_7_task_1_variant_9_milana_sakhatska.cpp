#include <iostream>   
#include <cstdarg>   

using namespace std;


double min(const char type, int count, ...) {
    va_list args;     
    va_start(args, count);  
    
    double minimum;   

    
    if (type == 'i') {
        minimum = va_arg(args, int);  

        for (int i = 1; i < count; ++i) { 
            int value = va_arg(args, int); 
            if (value < minimum) {        
                minimum = value;           
            }
        }
    } else if (type == 'd') {
        minimum = va_arg(args, double); 

        for (int i = 1; i < count; ++i) { 
            double value = va_arg(args, double); 
            if (value < minimum) {               
                minimum = value;                
            }
        }
    }

    va_end(args); 
    return minimum;
}

int main() {
   
    cout << "Мінімальне серед цілих чисел (5 елементів): " 
         << min('i', 5, 3, 7, 1, 9, 4) << endl;
    
    cout << "Мінімальне серед дійсних чисел (10 елементів): " 
         << min('d', 10, 5.5, 2.2, 3.3, 1.1, 4.4, 6.6, 8.8, 0.9, 7.7, 9.9) << endl;

    cout << "Мінімальне серед дійсних чисел (12 елементів): " 
         << min('d', 12, 15.5, 12.2, 13.3, 21.1, 14.4, 16.6, 18.8, 10.9, 17.7, 19.9, 11.1, 20.2) << endl;

    return 0; 
}
