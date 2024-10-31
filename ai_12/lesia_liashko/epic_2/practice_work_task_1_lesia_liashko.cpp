#include <iostream>
using namespace std;

int main () {

int n;
string choice;

cout<< "Please, choose the weather you have today: 1)sunny; 2)rainy; 3)cloudy; 4)snowy; 5)windy";
cin >> choice; 
 if (choice=="sunny"){
    n=1;
 }

  else if (choice == "rainy"){
    n=2;
 }
  else if (choice == "cloudy"){
    n=3;

    }
  else if (choice == "snowy"){
    n=4;

    }
  else if (choice == "windy"){
    n=5;

    }
  else { 
        cout<< "there is no a such weather, try again";
}
if (n==2 || n==4){
     cout<< "You need to wear a coat! ";
 } else {
     cout<< "You don't need a coat! ";
 }
 
 switch (n)
 {
 case 1:
         cout<< "It's perfect day for a picnic \n Wear your fav sneakers! ";

    break;
 case 2:
     cout<< "It's perfect day for reading a book at home \n Rain boots is a good idea! ";

    break;
 case 3:
     cout<< "Maybe you should visit a museum today \n You can wear whatever you want! ";

    break;
 case 4:
     cout<< "Don't you mind to make a snowman? \n You need to wear boots! ";

    break;
 case 5:
     cout<< "Fly a kite, if you have \n Wear something warm! ";

    break;
    default:
     cout<< "there is no a such weather, try again";
break;
 
 }


}