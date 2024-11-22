#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <algorithm> 

using namespace std;

void print_array(vector <int> array){
   for (int num: array){
        cout<<num<<" ";
     }
     cout<<endl;
}

int change_value(vector <int> &array){
   for (int num = 0; num < size(array);num++){
      if (array[num] % 2 == 0){
         array.insert(array.begin() + num, 0);
         num++;
      }
     }
     return 0;
}

int main(){
   
     vector <int> array;
     int number, value;
     
     cout<<"Number: ";
     cin>>number;

     srand(time(0));

     array.resize(number); 
     for (int &num: array){
        num = rand()% 100;
     }
     print_array(array);

     cout<<"Delete:";
     cin>>value;
     array.erase(remove(array.begin(), array.end(), value), array.end());
     print_array(array);
     change_value(array);
     print_array(array);
     
     return 0;
}
