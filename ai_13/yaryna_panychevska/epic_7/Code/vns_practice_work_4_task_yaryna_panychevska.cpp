#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "=================================="<<endl;
  for(int i = 1; i < 10; i++ )
  {
    if(i % 2 == 0)
    {
        continue;
    }
    else{
        cout << "The square of the number "<<i<<" is:\t"<<pow(i, 2)<<endl;
    }
  }
    return 0;
}