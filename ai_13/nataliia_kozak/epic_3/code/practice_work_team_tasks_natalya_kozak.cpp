#include <iostream>
#include <vector>
using namespace std;

int main(){
    bool running = true;
    int n = 7, index;
    vector<string> books_names = {"Anna Karenina", "To Kill a Mockingbird", "The Great Gatsby", "One Hundred Years of Solitude", "A Passage to India", "Invisible Man", "Don Quixote"};
    vector<bool> books_status(n, true);
    char answer;
    do{
        cout << endl << endl << "Welcome to the library, would you like to borrow (b), return (r) or check out (c) books? To exit - type (e)" << endl;
        cin >> answer;
        switch(answer){
            case 'b':
                borrowing:
                    cout << "Number of book you want to borrow(0-6)"<< endl;
                    cin >> index;
                    if (index >= 0 && index <=6){
                        if (books_status[index] == true){
                            cout << "Here's your book, enjoy!"<< endl;
                            books_status[index] = false;
                        }
                        else{
                            cout << "Sorry, book isn't available now." << endl;
                        }
                    }
                    else{
                        goto borrowing;
                    }
                    break;
            case 'r':
                returning:
                    cout << "Number of book you want to return(0-6)"<< endl;
                    cin >> index;
                    if (index >= 0 && index <=6){
                        cout << "Thank you! Have a nice day."<< endl;
                        books_status[index] = true;
                    }
                    else{
                        goto returning;
                    }
                    
                break;
            case 'c':
                for(string book : books_names){
                    cout << book << endl;
                }
                break;
            case 'e':
                running = false;
                break;
        }
    }
    while(running);
    return 0;

}