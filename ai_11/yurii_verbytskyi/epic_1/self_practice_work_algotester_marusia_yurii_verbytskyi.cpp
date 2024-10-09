#include <iostream>
using namespace std; 

int main()
{
   int num_packets; //кількість пачок
   int num_bis; //кількість печива в одній пачці;
   int mass[num_packets]; //масив
   int summa = 0;
    cout << "Number of packets: ";
    cin >> num_packets;
 for (int num_bis = 0; num_bis < num_packets; num_bis++)
 {
  cout << "Enter number " << num_bis+1 << ": ";
  cin >> mass[num_packets];

  summa += mass[num_packets];
 }
   
    
  int result = summa - num_packets;
   cout << result;
   
    return 0;
}
