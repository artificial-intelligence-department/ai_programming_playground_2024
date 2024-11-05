#include <iostream>

using namespace std;

int main()
{
    int ans=1;
    string books[5]={"Poliana","The C++ Programming Language","Measure, Integration & Real Analysis","Journey into Discrete Mathematics","English grammar"};
    bool ibooks[5]={1,1,1,1,1};
    menu:
    cout <<"Welcome to our library\n";
    cout <<"if you want to list all books you shoud to type \"1\" \n";
    cout <<"if you want to take a book you shoud to type \"2\" \n";
    cout <<"if you want to return the book you shoud to type \"3\" \n";
    int ans1;
    while (ans != 0)
    {
        do
        {
            int action;
            cout <<"what do you want to do\n";
            cin >> action;
            if (action==1)
            {
                cout << "we are having those books:\n";
                for(int i=0;i<5;i++)
                {
                    if (ibooks[i]==1)
                    {
                        cout << books[i] << "\n";
                    }                     
                }    
            }
            else if (action==2)
            {
                cout << "which book do you want to take?(1-5)\n";
                int number;
                cin >> number;
                if (number>5 || number<1)
                {
                    cout << " sorry, but we don't have this book\n";
                }
                else 
                {
                    if (ibooks[number-1]==0)
                    {
                        cout << "Sorry, but you already took this book\n";
                    }
                    else
                    {
                        ibooks[number-1]=0;
                    }                    
                }     
            }
            else if (action==3)
            {
                cout << "which book do you want to return the book?(1-5)\n";
                int number;
                cin >> number;
                if (number>5 || number<1)
                {
                    cout << " sorry, but we didn't have this book\n";
                }
                else 
                {
                    if (ibooks[number-1]==1)
                    {
                        cout << "Sorry, but you don't have this book\n";
                    }
                    else
                    {
                        ibooks[number-1]=1;
                    }                    
                }     
            }
            else
            {
                goto menu;
            }
            question:
            cout<<"if you want to continue type 1, else type 0 \n";
            cin>>ans1;
            if (ans1 != 1 && ans1 != 0)
            {
                cout << "I'm sorry, but I don't know this command\n so ";
                goto question;
            }
        }while (ans1==1);
    cout <<"if you want to exit the library you shoud to type \"0\" \n";
    cin >> ans;
    };
    return 0;   
}