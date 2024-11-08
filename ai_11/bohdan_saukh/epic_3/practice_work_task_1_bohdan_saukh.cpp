#include <iostream>
#include <string>

using namespace std;

int main()
{
    string books[] = {"C++", "Python", "Java"};
    bool booksAvailable[] = {1, 1, 1};

    string status;
    string take, give;
    string choice;

    int n = sizeof(books) / sizeof(books[0]);
    
    for (int i = 0; i < n; i++)
    {
        cout << books[i] << endl;
    }
    do{
    begining:
        cout << "Choose an option: take, return or status" << endl;
        cin >> choice;
        if (choice == "take"){
            cout << "What book do you want to take?" << endl;
            for (int i = 0; i < n; i++){
                if (booksAvailable[i] == 1){
                    cout << books[i] << endl;
                }else{
                    cout<<"Empty\n";
                }    
            }
            cin >> take;
            for (int i = 0; i < n; i++){
                if (take == books[i] && booksAvailable[i] == 1){
                    booksAvailable[i] = 0;
                }
            }
        }
        if (choice == "return"){
            cout << "What is the name of the book you return?" << endl;
            cin >> give;
            for (int i = 0; i < n; i++){
                if (booksAvailable[i] == 0 && books[i] == give){
                    booksAvailable[i] = 1;
                    break;
                }
            }
        }
        
        if(choice == "return" || choice == "status" || choice == "take"){
            for (int i = 0; i < n; i++){
                if (booksAvailable[i] == 1){
                    cout << books[i] << endl;
                }else{
                    cout<<"Empty\n";
                }    
            }
        }else{
            cout<<"This option does not exist\n";
        }
        
        cout << "Choose an option: menu or exit" << endl;

        cin >> status;
        if (status == "menu")
            goto begining;
    } while (status != "exit");

    return 0;
}