#include <iostream>
using namespace std;
int main ()
{
  string weather;
  cout << "Enter your current weather (sunny, rainy, cloudy, snowy, windy) : ";
  cin >> weather;
  if(weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy")
  {
    cout << "Please enter correct option";
    return 1;
  }

  if (weather == "rainy" || weather == "snowy" )
  cout << "put on a jacket" << endl;
  
  else 
  cout << "no jacket required" << endl; 

  if (weather == "sunny")
  cout << "A great day for a picnic!" << endl;

  else if (weather == "rainy")
  cout << "Perfect weather to read a book inside!" << endl;
  
  else if (weather == "cloudy")
  cout << "Maybe visit a museum?" << endl;

  else if (weather == "snowy")
  cout << "How about making a snowman?" << endl;

  else if (weather == "windy")
  cout << "Fly a kite if you have one!" << endl;

  switch (weather[1])
  {
  case 'u':
  cout << "Wear your favorite sneakers!";
  break;

  case 'a':
  cout << "Rain boots are a good idea!";
  break;

  case 'l':
  cout << "Today, any shoe is suitable.";
  break;

  case 'n':
  cout << "Snow boots will keep your feet warm!";
  break;

  default: cout << "Wear something sturdy!";
  break;
  }
  return 0;
}