#include <iostream>
using namespace std;

int main (){
  int N; 
  cin >> N;
  if (N<1 || N>1000)
  {
    cerr << "Error:Enter correct N";
    return 0;
  }

  int arr[N];

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
    if (arr[i]<1 || arr[i]>5)
    {
    cerr << "Error:Enter correct N";
    return 0;
    }  
  }
  int left_idx = 0;
  int right_idx = N-1;

  while(true){
    if (left_idx==right_idx)
    {
      cout << left_idx+1 <<" "<< right_idx+1 << endl;
      cout << "Collision";
      break;
    }

    if(left_idx>right_idx)
    {
      cout << left_idx+1 <<" "<< right_idx+1 << endl;
      cout << "Miss";
      break;
    }

    if(left_idx+1==right_idx)
    {
    cout << left_idx+1 <<" "<< right_idx+1 << endl;
    cout << "Stopped";
    break;
    }

    left_idx += arr[left_idx];
    right_idx -= arr[right_idx];
  }
  return 0;
}