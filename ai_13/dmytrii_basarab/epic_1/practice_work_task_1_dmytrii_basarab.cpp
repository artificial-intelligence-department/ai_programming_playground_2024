#include <iostream>
#include <stdio.h>
#include <cmath>

int main() {
  double A,P;
  float r;
  int t,n;
  printf ("Money invested: ");
  scanf ("%lf",&P);
  printf ("persentage per year in decimal: ");
  scanf ("%f",&r);
  printf ("years: ");
  scanf ("%d", &t);
  printf ("profit per year(month(12),quarter(4),year(1)): ");
  scanf ("%d", &n);
  A = P* pow((1 + r/n), t*n);
  printf ("persentage: %.2f%%\n", (r*100));
  printf("After %d years with profit %d times you will get: %.2lf\n", t,n,A);
  printf ("You will earn: %.2lf\n", A - P );
}
