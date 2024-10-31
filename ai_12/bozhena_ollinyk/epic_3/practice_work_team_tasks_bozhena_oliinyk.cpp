#include <iostream>
using namespace std;

int main()
{
    int numOfBooks;
    cout << "Enter how many books is there in the library: " << endl;
    cin >> numOfBooks;

    string listOfBooks[100];
    string redactedList[100];

    for (int i = 0; i < numOfBooks; i++)
    {
        cout << "Enter book №" << i << " of the library:" << endl;
        cin >> listOfBooks[i];
        redactedList[i] = listOfBooks[i];
    }



    bool client = true;
    int n = numOfBooks;

    while (client)
    {
        string help, stay;

        bool rightBook = false;
        bool giveAssistance = true;
        bool present = false;
        bool presentBook = false;

    help:
        cout << "May I help you? (Yes/No)" << endl;
        cin >> help;
        if (help == "no" || help == "No" || help == "NO")
        {
            cout << "Suit yourself" << endl;
            giveAssistance = false;
        stay:
            cout << "Will you stay here? (Yes/No)" << endl;
            cin >> stay;
            if (stay == "no" || stay == "No" || stay == "NO")
            {
                client = false;
                break;
            }
            else if (stay == "yes" || stay == "Yes" || stay == "YES")
            {
                cout << "I`m here if you need me)" << endl;
            }
            else
            {
                goto stay;
            }
        }
        if (help == "yes" || help == "Yes" || help == "YES")
        {

            string operation, takenBook, know, anotherOp, givenBook;
            do
            {
            operation:
                cout << "Do you want to take a book or to give back one? (Take/Give)" << endl;
                cin >> operation;
                if (operation == "take" || operation == "Take" || operation == "TAKE")
                {
                takeBook:
                    cout << "Do you know which book you want to take? (Yes/No)" << endl;
                    cin >> know;
                    if (know == "yes" || know == "Yes" || know == "YES")
                    {
                        cout << "Write name of the book you want to take:" << endl;
                        cin >> takenBook;
                    }
                    else if (know == "no" || know == "No" || know == "NO")
                    {
                        cout << "Here's the list of books we own:" << endl;
                        for (int i = 0; i < n; i++)
                        {
                            cout << listOfBooks[i] << endl;
                        }
                        cout << "Write which one you'd like to take:" << endl;
                        cin >> takenBook;
                    }
                    else
                    {
                        goto takeBook;
                    }

                    for (string i : listOfBooks)
                    {
                        if (takenBook == i)
                        {
                            presentBook = true;
                        }
                    }

                    if (presentBook == true)
                    {
                        cout << "Here's your book)" << endl;
                        int b = 0;
                        do
                        {
                            if (takenBook == redactedList[b])
                            {
                                rightBook = true;
                                string temp = redactedList[b];
                                for (int j = b; j < n - 1; j++)
                                {
                                    redactedList[j] = redactedList[j + 1];
                                }
                                redactedList[n-1] = temp;
                            }
                            b++;
                        } while (!rightBook);

                        listOfBooks[0] = {0};

                        for (int i = 0; i < n - 1; i++)
                        {
                            listOfBooks[i] = redactedList[i];
                            cout << listOfBooks[i] << endl;
                        }

                        n--;
                    }
                    else
                    {
                        cout << "Sorry, seems like we don't have that book right now(" << endl;
                    }
                }
                else if (operation == "give" || operation == "Give" || operation == "GIVE")
                {
                    cout << "Write which book do you want to give?" << endl;
                    cin >> givenBook;
                    cout << "Thanks, I'll take that away!" << endl;

                    redactedList[n] = givenBook;
                    for (int i = 0; i < n + 1; i++)
                    {
                        listOfBooks[i] = redactedList[i];
                        cout << listOfBooks[i] << endl;
                    }
                    n++;
                }
                else
                {
                    goto operation;
                }

            anOp:
                cout << "Do you want to make another operation? (Yes/No)" << endl;
                cin >> anotherOp;
                if (anotherOp == "no" || anotherOp == "No" || anotherOp == "NO")
                {
                    giveAssistance = false;
                }
                else if (anotherOp == "yes" || anotherOp == "Yes" || anotherOp == "YES")
                {
                    cout << "Sure!" << endl;
                }
                else
                {
                    goto anOp;
                }
            } while (giveAssistance);
        }
        else
        {
            goto help;
        }
    }

    return 0;
}
