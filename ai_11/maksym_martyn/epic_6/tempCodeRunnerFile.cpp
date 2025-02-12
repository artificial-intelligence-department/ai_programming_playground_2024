#include <iostream>
#include <vector>
using namespace std;

//Найпростіші запити

int main() {
 int n, q; // розмір масиву і к-сть запитань 
 cin >> n >> q;

 vector<int> arr(n + 1);
 vector<int> prefix(n + 1, 0);

 for (int i = 1; i <= n; i++) {
  cin >> arr[i];
  prefix[i] = prefix[i - 1] + arr[i];
 }

 vector<int> results; // Масив для зберігання результатів

 while (q--) {
  int type;
  cin >> type;
  //типи запитань 1) suma елементів префіксного масиву на проміжку l - r ( префіксний[l] - префіксний[r] )   2) до елемента масиву(простого) + число
  if (type == 1) {
   int l, r;
   cin >> l >> r;
   results.push_back(prefix[r] - prefix[l - 1]);

  } else if (type == 2) {
   int idx, value;
   cin >> idx >> value;
   int diff = value;
   arr[idx] += diff;

   for (int i = idx; i <= n; i++) {
    prefix[i] += diff;
   }
  }
 }

 for (int result : results) {
  cout << result << endl;
 }

 return 0;
}
