#include <iostream>
#include <cmath>

using namespace std;
 
 long long factorial (int number){
     if (number == 0 || number == 1) {
        return 1;
    }
   return number * factorial(number-1);
 }

 int main (){
    int n;
    cin >> n;
  cout << factorial(n);
 }