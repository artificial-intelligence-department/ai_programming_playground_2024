#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

double function_1(double c , double d ,  double e ,  double a ,  double b , double f ){
    vector<double> base;
    
    double c1  = c , d1 = d , e1 = e;
    double a1 = a , b1 = b;
    double f1 = f;
    base.push_back(c1);
    base.push_back(d1);
    base.push_back(e1);
    base.push_back(a1);
    base.push_back(b1);
    base.push_back(f1);
    sort(base.begin() , base.end());
    
    
    if((base[5] + base[4] +base[3]) > 4*(base[2] + base[1] + base[0]))
        return((base[5] + base[4] +base[3]) + (base[2] + base[1] + base[0]));
    
    if ((base[5] + base[4] +base[3]) > 3*(base[2] + base[1] + base[0]))
        return((base[5] + base[4] +base[3]) /(base[2] + base[1] + base[0]));

    if ((base[5] + base[4] +base[3]) > 2*(base[2] + base[1] + base[0]))
          return((base[5] + base[4] +base[3]) * (base[2] + base[1] + base[0]));
    else 
        return(0);
  
}  


void function_2(double){
    for(int i = 0; i< 5 ; i++){
        
    }



    
}

int main()
{
    float a = 0, b = 0;
    int c = 0 , d = 0,e = 0;
    double f= 0 , x;
    const double war = 53;
    cin >> a >> b >> c >> d >> e >> f;
    x = function_1(c , d , e , a , b , f ) / war;
    double &pos = x;  
    function_2(pos);

  
    return 0;
}



