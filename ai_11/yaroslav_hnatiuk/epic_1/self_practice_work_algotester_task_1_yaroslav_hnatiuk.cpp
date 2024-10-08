#include <iostream>
using namespace std;

int main() {
  long long n, g = 0;
  cin >> n;
  for (long long i = 0, x; i < n; i++) {
      cin >> x;
      g += x - 1;
  }
  cout << g;
  return 0;
}
