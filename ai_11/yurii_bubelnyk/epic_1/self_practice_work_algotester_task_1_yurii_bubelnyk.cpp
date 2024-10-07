#include <iostream>
using namespace std;

void numberOfBill(int value, int valueOfBills[],int amountOfBills){

   int i = amountOfBills - 1;
   int number = 0;

   while (value > 0 && i >= 0){

      if(value/valueOfBills[i] >= 1){

         int count = value/valueOfBills[i];
         number += count;
         value -= count*valueOfBills[i];

         }
         i--;
      }
   cout << number;
}

int main(){

   int bills[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
   int size = sizeof(bills)/sizeof(bills[0]);
   int value;

   cin >> value;

   numberOfBill(value, bills, size);


   return 0;
}