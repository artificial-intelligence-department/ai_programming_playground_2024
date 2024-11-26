#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int num;
    string decision, decision1, entrance;
    vector <bool> available;
    vector <string> books = {
        "Clean Code", "Think Like a Programmer", "Code Complete"
    };
    string library_list[] = {"Clean Code", "Think Like a Programmer", "Code Complete"};
    for (int i = 0; i<books.size(); i++){
        available.push_back(true);
    }
    start:
        cout<<"Entered library"<<endl;
        cout<<"Book list: "<<endl;
        for (string i:books){
            cout<<i<<endl;
        }

    while (decision1 !="yes"){
        cout<<"Borrow, return or check books?"<<endl;
        cin>>decision;
        transform(decision.begin(), decision.end(), decision.begin(), ::tolower);
        if (decision == "borrow"){
            cout<<"Which book do u want to borrow?. Enter a number of the book: "<<endl;
            cin>>num;
            if (available[num - 1]){
                available[num - 1] = false;
                books[num - 1] = books.back();
                books.pop_back();
            }
            else{
                cout<<"Book is not in the list"<<endl;
                goto start;
            }
        }
        else if (decision == "return"){
            cout<<"Which book do u want to return?. Enter a number of the book: "<<endl;
            cin>>num;
            if (available[num - 1]){
                cout<<"Book is already in the list"<<endl;
                goto start;
            }
            else{
                available[num - 1] = true;
                books.push_back (library_list[num - 1]);
            }
        }
        else if (decision == "check"){
            cout<<"Available books: "<<endl;
            for(string i:books){
                cout<<i<<endl;
            }
        }
        cout<<"Do u want to exit?"<<endl;
        cin>>decision1;
        transform(decision1.begin(), decision1.end(), decision1.begin(), ::tolower);
    }
}