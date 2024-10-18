#include <iostream>


int main (){   

  int m=1, n=4;
  int a = m-++n;
  int b = ++m>--n;
  int c = --n<++m;
  std::cout << a <<std::endl << b <<std::endl <<c; 
    
    return 0;
}
