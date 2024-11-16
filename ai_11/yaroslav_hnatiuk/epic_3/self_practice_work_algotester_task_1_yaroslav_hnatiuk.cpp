#include <iostream>
using namespace std;

int main() {
  long long n, k, v, g = 0, mx = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v;
    if (v >= k) {
      g++;
      if (g > mx) mx = g;
    } else if (v < k) g = 0;
  }
  cout << mx;
  return 0;
}

// n - кількість зубів
// k - мінімальний рівень загострення щоб вважати загостреним
// v - рівень загосрення поточного зуба
// g - кількість загострених поспіль


