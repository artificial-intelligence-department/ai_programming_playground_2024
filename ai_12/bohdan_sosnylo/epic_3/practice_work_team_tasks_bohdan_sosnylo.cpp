#include <iostream>
#include <string>
using namespace std;


int main(){
int i;
string k,choice;
string m[25] = {"1984", "To Kill a Mockingbird", "The Little Prince", "The Great Gatsby", "War and Peace",
        "One Hundred Years of Solitude", "Harry Potter and the Philosopher's Stone", "The Lord of the Rings",
 "Anna Karenina", "Moby Dick", "Pride and Prejudice", "Unchanged on the Western Front",
 "Fahrenheit 451", "A Thousand Shining Suns", "The Alchemist", "Crime and Punishment",
 "Portrait of Dorian Gray", "Lady Chatterley's Lover", "Les Miserables", "Little Women",
 "The Catcher in the Rye", "The Name of the Rose", "Over the Chasm in the Rye", "The Forsyth Saga",
 "Da Vinci Code"};
string a[25] = {"y","n","y","n","y","y","y","n","y","n","y","y","n","y","n","y","y","y","y","y","n","n","n","y","y"};
cout << "Welcome to our library, what do you want?"<<endl;


while(true){
    menu:
    cout << "\nMenu: ";
    cout << "Enter '1': List all books, ";
    cout << "Enter '2': Take the book, ";
    cout << "Enter '3': Return the book, ";
    cout << "Enter '4': Exit\n";
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore(32767, '\n');
    bool found = false;
    if(choice == "1"){
        for(i = 0;i<25;i++){
            cout <<m[i]<<endl;
        }
    }
    else if(choice == "2"){
        cout <<"which book would you like to choose?"<<endl;
        string r;
        getline(cin,r);
        i = 0;
        for(string t:m){
            if(r == t){
                found = true;
                if(a[i] == "n"){
                    cout << "unfortunately, the book is not available, maybe another time"<< endl;
                    
                }
                else if(a[i] == "y") {
                    cout << "Take your book but don't forget to return it!"<< endl;
                    a[i] = "ob";
                }
                else if(a[i] == "ob"){
                    cout << "you already have it anyway, we won't give it anymore, I'm sending you to the menu"<<endl;
                    goto menu;
                }
            }

            i++;
            }
            if(!found){
                cout << "Sorry, we don't have this book"<<endl;
                goto menu;
            }   
    }
    else if(choice == "3"){
        cout << "Enter the book you wish to return: "<<endl;
        string r;
        getline(cin,r);
        i = 0;
        for(string t:m){
            if(r == t){
                if(a[i] == "ob"){
                    a[i] = "y";
                    cout << "Okay, you've returned the book!"<<endl;
                }
                else{
                    cout << "Sorry, but you didn't pick up this book, I'll take you back to the main menu" <<endl;
                    goto menu;
                }
            }
        i++;
        }
    }
    else if(choice == "4"){
        cout << "Thank you for your trust, all the best"<<endl;
        return 0;
    }
    else{
        cout << "Wrong choice. Try again.\n";
            goto menu;
    }
    char m;
    do{
        
        cout <<"Do you want to perform another operation? (y/n): ";
        cin >>m;
    
    }while(m != 'y' && m != 'n');
    if (m == 'n') {
        cout << "Thank you for using the library!\n"; 
        return 0;
    }

}

    return 0;
}
