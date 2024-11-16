#include <iostream>
#include <vector>
using namespace std;

int main() {
int N;
cin >> N;

vector<int> r(N);
for (int i = 0; i < N; ++i) {
   cin >> r[i];
}

int a, b, c;
cin >> a >> b >> c;

vector<int> newmass;
for (int i = 0; i < N; ++i) {
   if (r[i] != a && r[i] != b && r[i] != c) {
      newmass.push_back(r[i]);
   }
}

int M = newmass.size() - 1;
if (M <= 0) {
   cout << 0 << endl;
   return 0;
}

vector<int> sums(M);
for (int i = 0; i < M; ++i) {
   sums[i] = newmass[i] + newmass[i + 1];
}


cout << M << endl;
for (int sum : sums) {
   cout << sum << " ";
}
cout << endl;

   return 0;
}
