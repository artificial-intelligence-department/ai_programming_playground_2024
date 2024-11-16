#include <iostream>
using namespace std;
int main ()
{
  int n,m;
  cout << "enter n and m : ";
  cin >> n >> m;
  int first_result = n++ - m;
  cout << "1) n++ - m = " << first_result << endl; // n will be +1 after result cause n++ not ++n ;)
  cout << "0 is false, 1 is true" << endl;
  bool second_result = m-- > n;
  cout << "2) m-- > n is " << second_result << endl;
  bool third_result = n-- > m;
  cout << "3) n-- > n is " << third_result << endl;
  return 0;
}