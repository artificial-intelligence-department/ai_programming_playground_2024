#include <iostream>
using namespace std;

int main() {
  long long packNum, allowToEat = 0;
  cin >> packNum;
  for (long long i = 0; i < packNum; i++) {
      int cookieNum;
      cin >> cookieNum;
      allowToEat += cookieNum - 1;
  }
  cout << allowToEat;
  return 0;
}

