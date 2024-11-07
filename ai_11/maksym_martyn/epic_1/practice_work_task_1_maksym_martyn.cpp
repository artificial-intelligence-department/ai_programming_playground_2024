#include <stdio.h>
#include <cmath>

int main ()
{
  double A, P , r;
  int t, n;
  //A - Майбутня загальна сума інвестиції, включаючи відсотки
  //P - Основна сума інвестиції
  //n - кількість нарахувань відсотків на рік
  //r - річна процентна ставка (у десятковій формі, тобто 5% = 0,05)
  //t - час, на який гроші інвестуються, у роках

  printf("Enter principal amount : ");
  scanf("%lf", &P );

  printf ("Enter the annual interest rate (r) in decimal form (e.g. 5%% = 0.05): ");
  scanf ("%lf" , &r);

  if (r <= 0) 
  {
    printf("Error: Interest rate must be greater than 0.\n");
    return 1;
  }

  printf ("Enter the number of interest charges per year (type only 1,4,12) : ");
  scanf("%d", &n);

  switch (n)
  {
  case 1:
  printf("You chose yearly compounding\n");
  break;

  case 4: 
  printf("You chose quarterly compounding\n");
  break;

  case 12:
  printf("You chose monthly compounding\n");
  break;
  
  default:
  printf("Invalid input. Please enter 12 for monthly, 4 for quarterly, or 1 for yearly.\n");
  return 1;
  }

  printf("Enter the investment time (in years): ");
  scanf("%d", &t);

  A = P * pow((1 + r / n), n * t);
  printf("The total investment amount after %d years is: %.2lf\n", t, A);
  printf("The profit earned is: %.2lf\n", A - P);
  return 0;
}