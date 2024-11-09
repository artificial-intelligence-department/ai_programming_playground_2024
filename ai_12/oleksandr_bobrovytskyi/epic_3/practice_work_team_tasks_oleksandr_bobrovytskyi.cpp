#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string> BookNames {"1.The lord of the rings", "2.Harry Potter", "3.The little prince", "4.Nineteen eighty four", "5.Don Quixote", "6.Bible"};
    int LibrarySize = BookNames.size();
    vector<string> AvailabilityOfBook(LibrarySize, "Available");
    int Option = 1; 
    int SelectedBook = 0;
    int temp = 0;

    cout << "What do you wish to do? \n";
    cout << " 0 - Exit\n";
    cout << " 1 - Borrow a book \n";
    cout << " 2 - Return a book \n";
    cout << " 3 - Get the list of the books\n";
    

    while(Option != 0)
    {
        do
        {
            cout << "Type in the number of the option that you want to pick: ";
            cin >> Option;

            for(string status : AvailabilityOfBook)
                {
                    if(status == "Available")
                    {
                        temp++;
                    }

                    if(temp == LibrarySize)
                    {
                        cout << "All books are available\n";
                    }
                }

            switch (Option)
            {
            case 1:
            TryAgainBorrow:            
                cout << "Select the book for borrowing by typing in its number: \n";
                cin >> SelectedBook;
                if(SelectedBook <= LibrarySize &&  AvailabilityOfBook[SelectedBook - 1] != "Unavailable")
                {
                    cout << "You have borrowed book " << BookNames[SelectedBook - 1] << endl; 
                    AvailabilityOfBook[SelectedBook - 1] = "Unavailable";
                }
                else if ( AvailabilityOfBook[SelectedBook - 1] == "Unavailable")
                {
                    cout << "Sorry, this book is already taken.\n";
                }
                else
                {
                    cout << "Invalid option, please try again.\n";
                    goto TryAgainBorrow;
                }
                break;
            case 2:
            TryAgainReturn:
                cout << "Type in the number of the book that you want to return.\n";
                cin >> SelectedBook;
                if(SelectedBook <= LibrarySize &&  AvailabilityOfBook[SelectedBook - 1] == "Unavailable")
                {
                    cout << "You have returned book " << BookNames[SelectedBook - 1] << endl; 
                    AvailabilityOfBook[SelectedBook - 1] = "Available";
                }
                else if ( AvailabilityOfBook[SelectedBook - 1] == "Available")
                {
                    cout << "Sorry, this book has been already returned.\n";
                }
                else
                {
                    cout << "Invalid option, please try again.\n";
                    goto TryAgainReturn;
                }
                break;
            case 3:
                cout << "The list of the books: \n";
                for(int i = 0; i < LibrarySize; i++)
                {   
                    cout << BookNames[i] << " -" << AvailabilityOfBook[i] << endl;
                }
                break;
            }
        } while (Option != 0);
    }

    return 0;
}