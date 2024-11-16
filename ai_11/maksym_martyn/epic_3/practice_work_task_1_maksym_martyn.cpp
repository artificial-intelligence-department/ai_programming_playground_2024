#include <iostream>
#include <vector>
#include <string>
using namespace std;

void listBooks (const vector <string> &books , const vector <bool> &availability){
  cout << "list of books: \n";
  for(int i= 0 ; i < books.size();i++){
    cout << i+1 << ')' << books[i];
    if(availability[i]){
      cout << " is available\n";
    } else {
      cout << " is not available\n";
    }
  }
}

void borrowBook (vector <bool> &availability){
  int bookNumber;
  cout << "Enter number of book which you want to choose: ";
  cin >> bookNumber;

  if(bookNumber < 1 || bookNumber > availability.size()){
    cout << "Not correct number";
    return;
  }
  
  if (availability[bookNumber-1]){
    availability[bookNumber-1] = false;
    cout << "You borrow the book\n";
  } else {
    cout << "That book was borrowed\n";
  }
}

void returnBook (vector<bool> &availability){
  int bookNumber;
  cout << "Enter number of book which to return ";
  cin >> bookNumber;
  if(bookNumber < 1 || bookNumber > availability.size()){
    cout << "not correct number";
    return;
  }
  if(!availability[bookNumber-1]){
    availability[bookNumber-1] = true;
    cout << "You return the book\n";
  } else {
    cout << "book is available\n";
  }
}

int main(){
  vector <string> books = {"book 1" , "book 2" , "book 3" , "book 4"};
  vector <bool> availability(books.size(),true);

  int choice;
  bool continueProgram = true;

  while(continueProgram){
  main_menu:
  
  cout << "\nMenu:\n";
  cout << "1. View all books\n";
  cout << "2. Borrow a book\n";
  cout << "3. Return a book\n";
  cout << "4. Exit\n";
  cout << "Your choice: ";
  cin >> choice;
  
  switch (choice) {
  case 1:
    listBooks(books,availability);
    break;
  case 2:
    borrowBook(availability);
    break;
  case 3:
    returnBook(availability);
    break;
  case 4:
    continueProgram = false;
    break;
  default:
    cout << "Not correct choice, try again pls";
    goto main_menu;
  }

  if(!continueProgram)
  break;

  char anotherOption;
  do {
    cout << "Do you want to perform another operation? Y/N" << endl;
    cin >> anotherOption;
    if(anotherOption == 'n' || anotherOption == 'N'){
      continueProgram = false;
      break;
    } else if (anotherOption == 'y' || anotherOption == 'Y'){
      break;
    } else {
      cout << "Not correct choice";
    }
  } while (true);
}

  cout << "End";
  return 0;
}