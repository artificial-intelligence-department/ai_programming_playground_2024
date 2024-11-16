#include <iostream>

using namespace std;

int main()
{
    int booksNum;
    cout << "Enter number of books in the library: " << "\n";
    cin >> booksNum;

    string bookList[100];
    string list1[100];

    for(int i = 0; i < booksNum; i++)
    {
        cout << "Enter book number" << i << " of the library: " << "\n";
        cin >> bookList[i];
        list1[i] = bookList[i];
    }

    bool client = true;
    int n = booksNum;

    while(client)
    {
        string help, stay;

        bool rightBook = false;
        bool assistance = true;
        bool present = false;
        bool bookPresent = false;

        help:
        cout << "Can I help you to chhose the best item? (Yes/No)" << "\n";
        cin >> help;
        if(help == "No" || help == "no" || help == "NO")
        {
            cout << "Choose by yourself" << "\n";
            assistance = false;

            stay:
            cout << "Are you going to stay here?(Yes/No)" << "\n";
            cin >> stay;
            if(stay == "No" || stay == "no" || stay == "NO")
            {
                client = false;
                break;
            }

            else if(stay == "Yes" || stay == "yes" || stay == "YES")
            {
                cout << "I am just here if you need me!" << "\n";
            }
            else
            {
                goto stay;
            }
        }
        if(help == "Yes" || help == "yes" || help == "YES")
        {
            string operation, take, knows, another, give;
            do
            {
                operation:
                cout << "Do you want to take a new book or to give back the old one?(Take/Give)" << "\n";
                cin >> operation;
                if(operation == "Take" || operation == "take" || operation == "TAKE")
                {
                    take:
                    cout << "Do you know which book you are looking for?(Yes/No)" << "\n";
                    cin >> knows;
                    if(knows == "Yes" || knows == "yes" || knows == "YES")
                    {
                        cout << "Write name of the book you want to take: " << "\n";
                        cin >> take;
                    }

                    else if(knows == "No" || knows == "no" || knows == "NO")
                    {
                        cout << "Here is the list of books we have: " << "\n";
                        for(int i = 0; i < n; i++)
                        {
                            cout << bookList[i] << "\n";
                        }
                        cout << "Write which book you want to take: " << "\n";
                        cin >> take;
                    }
                    else
                    {
                        goto take;
                    }

                    for(string i : bookList)
                    {
                        if(take == i)
                        {
                            bookPresent = true;
                        }
                    }

                    if(bookPresent == true)
                    {
                        cout << "Here is your book" << "\n";
                        int b = 0;
                        do
                        {
                            if(take == list1[b])
                            {
                                rightBook = true;
                                string temp = list1[b];
                                for(int j = b; j < n - 1; j++)
                                {
                                    list1[j] = list1[j + 1];
                                }
                                list1[n - 1] = temp;
                            }
                            b++;
                        } while (!rightBook);

                        bookList[0] = {0};

                        for(int i = 0; i < n - 1; i++)
                        {
                            bookList[i] = list1[i];
                            cout << bookList[i] << "\n";
                        }
                        n--;
                    }
                    else
                    {
                        cout << "Sorry, but we don't have this book right now" << "\n";
                    }
                }
                else if(operation == "Give" || operation == "give" || operation == "GIVE")
                {
                    cout << "Write name of the book which you want to give?" << "\n";
                    cin >> give;
                    cout << "Thank you, I will take it away!" << "\n";

                    list1[n] = give;
                    for(int i = 0; i < n + 1; i++)
                    {
                        bookList[i] = list1[i];
                        cout << bookList[i] << "\n";
                    }
                    n++;
                }
                else
                {
                    goto operation;
                }

                anOp:
                cout << "Do you want to make another operation?(Yes/No)" << "\n";
                cin >> another;
                if(another == "No" || another == "no" || another == "NO")
                {
                    assistance = false;
                }
                else if(another == "Yes" || another == "yes" || another == "YES")
                {
                    cout << "Ofcourse!" << "\n";
                }
                else
                {
                    goto anOp;
                }
            } while(assistance);
        }
        else
        {
            goto help;
        }
    }
    return 0;
}