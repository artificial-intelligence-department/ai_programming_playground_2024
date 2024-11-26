#include <iostream>   
#include <cmath>      
using namespace std;  

int main() {
    double epsilon = 0.0001;  
    double sum = 0.0;        
    double term;             
    int n;                 

   
    cout << "Введіть значення n: ";
    cin >> n;  

  
    term = pow(10, 0) / tgamma(1); 

    int i = 0; 

   
    while (i < n && term >= epsilon) {
        sum += term;                         
        i++;                                
        term = pow(10, i) / tgamma(i + 1);   
    }

    
    cout << "Сума ряду з точністю " << epsilon << " і " << n << " членів дорівнює: " << sum << endl;

    return 0; 
}
