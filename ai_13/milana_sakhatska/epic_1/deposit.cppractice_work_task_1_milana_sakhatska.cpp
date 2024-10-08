#include <stdio.h>  
#include <math.h>  
 

int main() { 
 int i; 

 printf("Введіть суму інвестиції: \n"); 

 scanf("%i", &i); 



 float p; 

 printf(":Введіть річну процентну ставку: \n"); 

 scanf("%f", &p); 

p /= 100.0; 



 int n; 
 printf("Введіть суму відсотків на рік: \n"); 

 scanf("%i", &n); 



 int t; 

 printf("Введіть час інвестиції суми(роки): \n"); 

 scanf("%i", &t); 


 float a = 1 + p / n; 
 float A = i * pow(a, t * n); 

 A = round(A * 100) / 100; 

 
 printf("Інвестиція: \n"); 

 printf("Сума інвестиції: %i\n", i); 

 printf("Загальна сума інвестиції: %.2f\n", A); 

 printf("Зароблено: %.2f", (A - i)); 
 
 
 return 0; 
}