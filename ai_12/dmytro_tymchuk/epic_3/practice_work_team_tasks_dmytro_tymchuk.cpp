#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int option = 0, flag = 0;
    int choosen_book = 0, choose_or_return = 0;
    string returning_book;
    std::vector<string> books = {"The Lord of the rings",
                                "The gates of Europe",
                                "Harry Potter and the sorcerer's stone",
                                "Game of Thrones",
                                "Pet Sematary",
                                "1984"
                                };

    
    while (option!=4)
    {
        Menu:
        cout<<"Choose an option:"<<endl;
        cout<<"1) List books"<<endl;
        cout<<"2) Take book"<<endl;
        cout<<"3) Return book"<<endl;
        cout<<"4) Exit"<<endl;
        cin>>option;

        //// Список книг
        if (option == 1)
        {
            for (int i = 0; i < books.size();i++)
            {
                cout<<i + 1<<") "<<books[i]<<endl;
            }

            cout<<"Do you want to choose other option?"<<endl;
            cout<<"1) YES"<<endl;
            cout<<"2) NO"<<endl;
            cin>>flag;

            if (flag == 1) goto Menu;
            else option = 4;
        }
        //// Список книг
        
        //// Взяти книгу
        else if (option == 2)
        {
            choose_or_return = 0;
            do
            {
                cout<<"Which book do you want to take?"<<endl;
                for (int i = 0; i < books.size(); i++)
                {
                    cout<<i + 1<<") "<<books[i]<<endl;
                }

                cin>>choosen_book;

                if (choosen_book - 1 < books.size()) 
                {
                    books.erase(books.begin() + choosen_book - 1);
                    cout<< "\nWe hope that you will like this one\n\n";
                    cout<<"Do you want to choose other option?"<<endl;
                    cout<<"1) YES"<<endl;
                    cout<<"2) NO"<<endl;
                    cin>>flag;

                    if (flag == 1) goto Menu;
                    else option = 4;
                }
                else
                {
                    cout<<"We don`t have this book"<<endl;
                    cout<<"Choose another or return to the menu:"<<endl;
                    cout<<"1) Choose another"<<endl;
                    cout<<"2) Go to menu"<<endl;

                    cin>>choose_or_return;
                }
            } while (choose_or_return == 1);
            if (choose_or_return == 2) goto Menu;
        }
        //// Взяти книгу

        //// Віддати книгу
        else if (option == 3)
        {
            cout<<"Which book you want to return?"<<endl;
            cin >> returning_book;
            books.push_back(returning_book);
            cout<<"\nThank you for returning the book :)\n\n";

            cout<<"Do you want to choose other option?"<<endl;
            cout<<"1) YES"<<endl;
            cout<<"2) NO"<<endl;
            cin>>flag;

            if (flag == 1) goto Menu;
            else option = 4;
        }
        //// Віддати книгу

        //// Перевірка на правильність вибору команди
        else if (option != 4)
        {
            cout<<"You choosed wrong option\nPlease choose another one\n";
            goto Menu;
        }

        //// Перевірка на правильність вибору команди

    }
    return 0;
}