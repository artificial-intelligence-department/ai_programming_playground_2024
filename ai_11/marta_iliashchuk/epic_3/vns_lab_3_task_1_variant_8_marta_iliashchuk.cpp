#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
   const double pi = acos(-1);
   const double epsilon = 0.0001;
   double k = 0.07;
   double x[11];
   double y;
   int m;
   int n;
   double sum_1;
   double S;
   double sum_1e;
   double S_e;

   for(int i=0; i<11; i++){
      x[i] = 0.1 + k*i;
      y = x[i]*sin(pi/4)/( 1 + pow(x[i], 2) - 2*x[i]*cos(pi/4 ));


      S = 0;
      for(int n = 1; n<=40; n++){
         sum_1 = pow(x[i], n)*sin(n*pi/4);
         S+= sum_1;
      }


      S_e = 0;
      m = 1;
      do{
         sum_1e = pow(x[i], m)*sin(m*pi/4);
         S_e+=sum_1e;
         m++;
      }while(abs(sum_1e)>=epsilon);


      cout<<fixed<<setprecision(4);
      cout<<x[i]<<"   "<<S<<"   "<<S_e<<"   "<<y<<endl;
   }   

return 0;
}