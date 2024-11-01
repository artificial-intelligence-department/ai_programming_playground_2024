#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> List ({
    "1. 1984",
    "2. To Kill a Mockingbird",
    "3. One Hundred Years of Solitude",
    "4. Pride and Prejudice",
    "5. The Great Gatsby",
    "6. Brave New World",
    "7. The Catcher in the Rye",
    "8. Moby Dick",
    "9. Crime and Punishment",
    "10. The Hobbit",
});

vector<bool> Availability ({true, false, false, false, true, true, false, false, false, true});

int main(){
    int choice;
    while(1){
        cout<<"Choose the option:"<<endl;
        cout<<"1. Display the full list of books"<<endl;
        cout<<"2. Take the book"<<endl;
        cout<<"3. Return the book"<<endl;
        cout<<"4. Exit the menu"<<endl;
        cin>>choice;
        cout<<endl;
        switch (choice){
            case 1:
                cout<<"Full list of the books:"<<endl;
                for(const auto& book: List){
                    cout<<book<<endl;
                    }
                cout<<endl;
                break;
            case 2:
            while(1){
                cout<<"List of available books"<<endl;
                for(int i=0; i<List.size(); i++){
                    if (Availability[i]){
                        cout<<List[i]<<endl;
                        }
                    }
                cout<<"Enter the number of one you want to take: ";
                int choice2;
                cin>>choice2;
                if(Availability[choice2-1]==0){
                    cout<<"This book is not available, choose another one."<<endl;
                }
                if(Availability[choice2-1]==1){
                    cout<<"Happy reading!"<<endl<<endl;
                    Availability[choice2-1]=0;
                    break;
                }
                }
                break;
            case 3:
                while(1){
                cout<<"List of books to return:"<<endl;
                for(int i=0; i<List.size(); i++){
                    if (Availability[i]!=1){
                        cout<<List[i]<<endl;
                        }
                    }
                cout<<"Enter the number of one you want to return: ";
                int choice2;
                cin>>choice2;
                if(Availability[choice2-1]==1){
                    cout<<"This book is already here, choose another one."<<endl;
                }
                if(Availability[choice2-1]==0){
                    cout<<"See you soon!"<<endl<<endl;
                    Availability[choice2-1]=1;
                    break;
                }
                }
                break;
            case 4:
                return 0;

            default: 
                cout<<"Enter correct option";
                break;
        }
    }
    
    return 0;
}