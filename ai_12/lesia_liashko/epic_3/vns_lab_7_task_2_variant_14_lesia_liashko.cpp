#include <iostream>
#include <cmath>
using namespace std;


double findln (double x){
    return log(x);
}

double findlog (double x, int ten){
    if (ten==10){
        double log = log10(x);
        return log;
    }  
    else {
         cout << "Wrong step";
         return -1; 
    }

}

int main (){
    cout << "Enter a number" << endl;
    double n;
    cin >> n;

    if (n<=0){
        cout << "Wrong" << endl;
      return 1;

    }
    
    
    double ln = findln (n);
    double log = findlog (n,10);
    cout << "ln"<< n << "="<< ln << endl;
    cout << "log10(" << n <<  ")=" << log << endl;
    
    return 0;
}