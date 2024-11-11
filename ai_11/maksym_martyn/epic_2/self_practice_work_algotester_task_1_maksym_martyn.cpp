//https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/20075
#include <iostream>
using namespace std;

int main () 
{
  long long n,k;
  const long long limit_1 = 1000000, limit_2 = 10000000000;
  cin >> n >> k;
  if(n<1 || n>limit_1 || k<1 || k>limit_2)
  {
    return 0;
  }

  long long a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i]<1 || a[i]>limit_2)
    {
      return 0;
    }
  }
  long long current_count = 0;
  long long max_count = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i]>=k)
    {
      current_count++;
    }
    else
    {
      if (current_count>max_count)
      {
        max_count = current_count;
      }
      current_count = 0;
    }
  }

  if (current_count > max_count)
  {
    max_count = current_count;
  }
  
  cout << max_count;
  return 0;
}