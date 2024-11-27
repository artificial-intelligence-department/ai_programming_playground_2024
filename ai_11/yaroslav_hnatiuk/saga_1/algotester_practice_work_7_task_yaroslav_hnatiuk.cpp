#include <iostream>
using namespace std;

int main() {
  long long N, numA = 0, numK = 0, numN = 0, numP = 0;
  string str;
  cin >> N;
  cin >> str;
  for (int i = 0; i < N; i++) {
    if (str[i] == 'a') numA += 1;
    else if (str[i] == 'k') numK += 1;
    else if (str[i] == 'n') numN += 1;
    else if (str[i] == 'p') numP += 1;
  }

  if (numA < 3 || numK < 2 || numN < 1 || numP < 1) cout << 0;
  else if (numA == 3 && numK == 2 && numN == 1 && numP == 1) cout << 1;
  else {
    numA -= 3;
    numK -= 2;
    numN -= 1;
    numP -= 1;
    cout << min(min(min(numA / 2, numK), numN), numP) + 1;
  } 

  return 0;
}

