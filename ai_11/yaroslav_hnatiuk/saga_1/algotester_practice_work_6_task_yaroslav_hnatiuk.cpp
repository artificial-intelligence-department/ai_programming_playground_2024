#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, numK = 0, numV = 0, partK = 0, partV = 0;
  string txt;
  cin >> N;
  cin >> txt;
  for (int i = 0; i < N; i++) {
    if (txt[i] == 'K') numK++;
    else numV++;

    if (numK >= 11 && numK - 2 >= numV) {
      partK++;
      numK = 0;
      numV = 0;
    }
    else if (numV >= 11 && numV - 2 >= numK) {
      partV++;
      numK = 0;
      numV = 0;
    } 
  }

  cout << partK << ':' << partV << endl;
  if (numK != 0 || numV != 0) cout  << numK << ':' << numV;
  
  return 0;
}

