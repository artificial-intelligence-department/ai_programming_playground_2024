#include<iostream>
#include<vector>
#include<string>
using namespace std;


void printBook(string bookName, bool isAvailable)
{
    boolalpha(cout);
    cout << "Name: " << bookName << endl << "Is avaiable: " << isAvailable << endl;
}

bool contains(vector<string> books , string book)
{
    for (auto & b : books)
    {
        if(b == book)
        return true;
    }
    return false;
}

bool isAvailable(const vector<string>& books , string book, vector<bool>& availList)
{
    for (size_t i = 0; i < books.size(); i++)
    {
        if(books[i] == book)
        {
            return availList[i];
        }
    }
    return false;
}

int main()
{
    vector<string> books = { "Book1" , "Book2", "Book3", "Book4" };
    vector<bool> availibility = { true,true,true,true };

    bool inUse = true;
    int userOption;
    do 
    {
        START_MARK:
        cout << "Enter Operation:\n1.All books\n2.Take Book\n3.Put book back\n4.Exit\nYour option: ";
        cin >> userOption;
        switch (userOption)
        {
            case 1:
            {
                for (size_t i = 0; i < books.size(); i++)
                {
                    printBook(books[i], availibility[i]);
                }
                cout << endl;
                break;
            }
            case 2:
            {
                string bookN;
                cout << "Enter book name: ";
                cin >> bookN;
                int index = 0;
                bool takes = false;
                bookN.clear();
                for(const bool& each : availibility)
                {
                    if(each == true && contains(books,bookN))
                    {
                        cout << "Book successfully taken!\n";
                        takes = true;
                        index++;
                        break;
                    }
                    index++;
                }
                if(!takes)
                {
                    cout << "No " << bookN << " available!";
                    break;
                }
                takes = false;
                availibility[index] = false;
                break;
            }
            case 3:
            {
                string bookPn;
                cout << "Enter book name to put back: ";
                cin >> bookPn;
                for (size_t i = 0; i < books.size(); i++)
                {
                    if(books[i] == bookPn)
                    {
                        availibility[i] = true;
                        cout << "Book was put back!\n";
                        break;
                    }
                }
                break;
            }  
            case 4:
            {
                cout << "Goodbye!\n";
                // inUse = false;
                // goto END;
                return 0;
                break;
            }
            default:
            {
                cout << "Error option!\nTry again\n";
                goto START_MARK;
                break;
            }
        } 
    } while(inUse);

    END:
    return 0;
}