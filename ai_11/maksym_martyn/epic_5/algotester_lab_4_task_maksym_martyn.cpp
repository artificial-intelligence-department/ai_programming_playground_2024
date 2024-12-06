// Використання алгоритму STL

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  if (N<1 || N>1000){
    cerr << "Invalid N! Please restart program and try again";
    return 0;
  }
  int* arr = new int [N];

  for(int i = 0; i < N; i++){
    cin >> arr[i];
    if(arr[i]<0 || arr[i]>1000){
      cerr << "Invalid ai! Please restart program and try again";
      delete[] arr;
      return 0;
    }
  }

  int* group0 = new int[N];
  int* group1 = new int[N];
  int* group2 = new int[N];
  int size0 = 0, size1 = 0, size2 = 0;

  for (int i = 0; i < N; i++) {
    if (arr[i] % 3 == 0) {
      group0[size0++] = arr[i];
    } else if (arr[i] % 3 == 1) {
      group1[size1++] = arr[i];
    } else {
      group2[size2++] = arr[i];
    }
  }
  sort(group0, group0 + size0); //сортує у порядку зростання  
  sort(group1, group1 + size1, greater<int>()); //у порядку спадання
  sort(group2, group2 + size2); //у порядку зростання

  int* result = new int[N];
  int result_size = 0;

  auto add_unique = [&](int* group, int size) {
    for (int i = 0; i < size; i++) {
      bool exists = false;
      for (int j = 0; j < result_size; j++) {
        if (result[j] == group[i]) {
        exists = true;
        break;
        }
      }
      if (!exists) {
        result[result_size++] = group[i];
      }
    }
  };

  add_unique(group0, size0);
  add_unique(group1, size1);
  add_unique(group2, size2);
  
  cout << result_size << endl;
  for (int i = 0; i < result_size; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  delete[] arr;
  delete[] group0;
  delete[] group1;
  delete[] group2;
  delete[] result;

  return 0;
}