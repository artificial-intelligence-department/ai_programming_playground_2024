#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double epsilon = 0.0001;
    double sum = 0.0;
    double term = 1.0; 
    int n = 1;

    while(abs(term) >= epsilon){
        term = 1.0/((3*n-2)*(3*n+1));
        sum += term;
        n++;
    }
    cout<<"Сума ряду з точністю "<<epsilon<<"\nДорівює: "<<sum;
    return 0;
}