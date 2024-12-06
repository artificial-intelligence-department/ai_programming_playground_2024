// Використання алгоритму Merge Sort

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void merge(int* arr, int left, int mid, int right, bool ascending) {
  int n1 = mid - left + 1; // Розмір лівої частини
  int n2 = right - mid; // Розмір правої частини

  int* L = new int[n1];
  int* R = new int[n2];

  for (int i = 0; i < n1; i++){
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++){
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0;
  int k = left;

  while(i < n1 && j < n2){ //поки містять елементи
    bool condition = ascending ? (L[i] <= R[j]) : (L[i] >= R[j]);
    if (condition) {
     arr[k++] = L[i++];//arr — це вихідний масив, у який ми записуємо злиті дані.
    } else {
      arr[k++] = R[j++]; 
    }
  }

  while (i < n1) 
  arr[k++] = L[i++];

  while (j < n2) 
  arr[k++] = R[j++];

  delete[] L;
  delete[] R;
}

void mergeSort(int* arr, int left, int right, bool ascending) {
  if (left < right) {
    int mid = left + (right - left) / 2; 

    mergeSort(arr, left, mid, ascending);          // Сортуємо ліву частину
    mergeSort(arr, mid + 1, right, ascending);     // Сортуємо праву частину
    merge(arr, left, mid, right, ascending);       // Зливаємо частини
  }
}

void addUnique(int* group, int group_size, int* result, int& result_size) {
  for (int i = 0; i < group_size; i++) {
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
}
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

  mergeSort(group0, 0, size0 - 1, true);    // Зростання
  mergeSort(group1, 0, size1 - 1, false);  // Спадання
  mergeSort(group2, 0, size2 - 1, true);   // Зростання

  int* result = new int[N];
  int result_size = 0;

  addUnique(group0, size0, result, result_size);
  addUnique(group1, size1, result, result_size);
  addUnique(group2, size2, result, result_size);

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