#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
   vector<string>books = {"MyDog", "YourDog", "OurDog"};
   vector<bool>available  = {true,true,true};
   
   int choice;

  Menu:
  cout << "Choose from the menu:"<< endl;
  cout << "1. Show all books;"<< endl;
  cout << "2. Take a book;"<< endl;
  cout << "3. Allow to return the book;"<< endl;
  cout << "4. Exit"<< endl;
  
  cin >> choice;

switch (choice){
    case 1:{
        for (size_t i = 0; i < books.size(); i++) {
           cout << (i + 1) << ". " << books[i] << (available[i] ? " - available" : " - not available") << endl;
       }
    }
      break;
     
     case 2: {
        int abook;
        cout << "Choose a book you want to take" << endl;
        cin >> abook;
        
        if (abook < 1 || abook > books.size ()){
            cout << "Try again";
            goto Menu;
        }
        else if (!available[abook-1]) {
                cout << "It's not available" << endl;
                goto Menu;
         }
        else {available [abook-1]=false;
        cout << "You've borrowed " << books [abook-1] << endl;
        }      
     } 
     break;

     case 3: {
        int abook;
        cout << "What book do you want to return?" << endl;
        cin >> abook;

       if (abook < 1 || abook > books.size ()|| !available[abook-1]){
            cout << "Try again";
            goto Menu;
        } 
        else if (available [abook -1]){
         cout << "You didnt take that book" << endl;
        }
        else { available [abook-1]= true;
        cout << "Good job! "<< books [abook-1]<< " is returned"<< endl;
        }
      }
     break;

     case 4:
       return 0;

     default: 
       cout<< "try again" << endl;
       goto Menu;
       }
 
       string onemore;
       cout << "Do you want to see the main menu?\n Yes/No"<< endl;
       cin >> onemore;
       if (onemore == "No" || onemore != "Yes") {
        return 0;
       }
       else {
        goto Menu;
       }
 }




