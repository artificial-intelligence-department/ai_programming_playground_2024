#include <iostream>
using namespace std;

int main(){
  int M;
  int counter_both = 0;
  int N;
  cin >> N;
  if (N<0 || N>100)
  {
    cerr << "Too large";
    return 0;
  }
  
  int first_arr[N];
  for (int i = 0; i < N; i++)
  {
    cin >> first_arr[i];
    if (first_arr[i]<0 || first_arr[i]>100)
  {
    cerr << "Too large";
    return 0;
  }
  }
  
  cin >> M;
  int second_arr[M];
  for (int i = 0; i < M; i++)
  {
    cin >> second_arr[i];
    if (second_arr[i]<0 || second_arr[i]>100)
  {
    cerr << "Too large";
    return 0;
  }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (first_arr[i]==second_arr[j])
      {
        counter_both++;
        break;
      }
    }
  }
  int counter_uni = (M+N) - counter_both;
  cout << counter_both << '\n' << counter_uni;

  return 0;
}