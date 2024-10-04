#include <iostream>
using namespace std;

void toBinary(int a){

   int arr[32]{};
   int i = 0;

   while (i < 32){
      arr[i] = a % 2;
      a /= 2;
      i++;
   }

   for (int j = i - 1; j >= 0; j--){
      cout << arr[j];
   }

}

void toMinusBinary (int a){

   int arr[32]{};
   int i = 0;

   while (i < 32){
      arr[i] = !(a % 2);
      a /= 2;
      i++;
   }
   arr[0] = 1;
   for (int j = i - 1; j >= 0; j--){
      cout << arr[j];
   }

}

int main() {
   int value;
   cout << "Enter the value: ";
   cin >> value;

   toBinary(value);
   cout << endl;
   toMinusBinary(value);

   return 0;
}