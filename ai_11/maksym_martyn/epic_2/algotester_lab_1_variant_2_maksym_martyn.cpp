#include <iostream>
using namespace std;

int main ()
{
  const long long limit = 10000000000000;
  long long h[4];
  long long d[4];
  
  for (int i = 0; i < 4; i++)
  {
    cin >> h[i];
    if(h[i] < 0 || h[i] > limit)
    return 0;
  }
  
  for (int i = 0; i < 4; i++)
  {
    cin >> d[i];
    if(d[i] < 0 || d[i] > limit)
    return 0;
  }

  bool error_occurred = false;
  bool table_tipped = false;

  for (int i = 0; i < 4; i++)
  {
    if (h[i] < d[i])
    {
      error_occurred = true;
    }
    else
    {
    h[i] -= d[i];
    }
    
    long long max_h = h[0], min_h = h[0];

    for (int j = 1; j < 4; j++)
    {
      if(max_h < h[j])
      max_h = h[j];

      if(min_h > h[j])
      min_h = h[j];
    }

    if (max_h >= 2*min_h)
    {
      table_tipped = true;
    }
  }
  
  if(error_occurred)
  cout << "ERROR";

  else if(table_tipped)
  cout << "NO";

  else
  cout << "YES";

  return 0;
}

