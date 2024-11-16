//https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/25#mySolutions
#include <iostream>
#include <vector>
using namespace std;

namespace LotteryGame {
  int myMax(int a,int b){
  return (a>b) ? a : b;
  }

  int myMin(int a , int b){
  return (a<b) ? a : b;
  }
  int chooseColumnwithMinRowMax(const vector<vector<int>> &table , int n , int m){
    int minMaxvalue = 1001;
    int chosenColumn = 0;
    for (int j = 0; j<m ; j++){
      int maxInColumn = 0;
    for(int i = 0;i<n;i++){
      maxInColumn = myMax(maxInColumn , table[i][j]);
    }
    if (maxInColumn<minMaxvalue){
      minMaxvalue=maxInColumn;
      chosenColumn = j;
    }
    }
    return chosenColumn;
  }
  int chooseMaxInColumn(const vector<vector<int>> &table , int n , int chosenColumn){
    int maxValue = 0;
    for(int i = 0; i < n ;i++){
      maxValue = myMax (maxValue , table[i][chosenColumn]);
    }
    return maxValue;
  }
}

int main (){
  int n,m;
  cin >> n >> m;
  if ((n < 1 || n > 1000) || (m < 1 || m > 1000)) {
  cerr << "Error: Input values for n and m are out of bounds." << endl;
  return 1;
}

  vector<vector<int>> table (n, vector<int>(m));

  for (int i =0; i < n; i++){
    for(int j = 0;j < m;j++){
      cin >> table[i][j];
      if(table[i][j] < 1 || table[i][j] > 1000){
        cerr << "Error: Input values for a_ij are out of bounds." << endl;
        return 1;
      }
    }
  }
  int chosenColumn = LotteryGame::chooseColumnwithMinRowMax(table, n,m);
  int result = LotteryGame::chooseMaxInColumn(table,n,chosenColumn);
  cout << result;
  return 0;
}