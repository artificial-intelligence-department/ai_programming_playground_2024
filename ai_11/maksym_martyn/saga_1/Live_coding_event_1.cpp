#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double function_1(){
  double a,b,f;
  int c,d,e;

  cin >> a >> b;
  cin >> c >> d >> e;
  cin >> f;

  double arr [6] = {a, b,static_cast<double>(c),static_cast<double>(d),static_cast<double>(e),f};
  for (size_t i = 0; i < 5; i++)
  {
    for (size_t j = i+1; j < 6; j++)
    {
      if (arr[i] < arr[j])
      {
        double temp = arr[i];
        arr[i]=arr[j];  // buble sort 
        arr[j]=temp;
      }
    }
  }
  
  double sum_max = arr[0]+arr[1]+arr[2];
  double sum_min = arr[3]+arr[4]+arr[5];

  if (sum_max > sum_min*2)
  {
    return sum_max*sum_min;
  }
  else if (sum_max>sum_min*3)
  {
    return sum_max/sum_min;
  }
  else if (sum_max>sum_min*4)
  {
    return sum_max+sum_min;
  }
  else
  {
    return sum_max - sum_min; //якщо жодна умова не виконалась
  }
}

void function_2 (double&x , double matrix[5][5]){
  const int size = 5;
  const int variant = 18;

  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      matrix[i][j] = x;
    }
  }

  srand(time(0));
  for (int i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      matrix[i][j]=(matrix[i][j]+variant+j-i)*(rand()%100+1);
    }
  }
  cout << "Updated matrix: " << endl;
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

}

int main (){
  const int var = 18;
  double x = function_1();

  double matrix[5][5];
  
  function_2(x,matrix);

  
  return 0;
}