#include <iostream>
#include <string>
using namespace std;

int main(){
    string choice;
    bool r = true;
    cout<<"Enter weather condition(sunny, rainy, cloudy, snowy, windy): ";
    cin>>choice;
    if(choice == "sunny" || choice == "rainy" || choice == "cloudy" || choice == "snowy" || choice == "windy"){

        if (choice=="snowy" || choice=="rainy"){
            cout<<"You should put on your coat!"<<endl;
        }else{
            cout<<"You don't have to put a coat!"<<endl;
        }

        if (choice == "sunny"){
            cout<<"It's a good day for a picnic!"<<endl;
        }else if(choice == "rainy"){
            cout<<"It's recommended to read a book inside the house!"<<endl;
        }else if(choice == "cloudy"){
            cout<<"You can visit a museum!"<<endl;
        }else if(choice == "snowy"){
            cout<<"Let's make a snowman!"<<endl;
        }else if(choice == "windy"){
            cout<<"If you have a kite you can fly it!"<<endl;
        }

        switch (choice[0])
        {
        case 's':
            if (choice == "sunny"){
            cout<<"Put your favourite sneakers!"<<endl;
            }
            else if(choice == "snowy"){
            cout<<"Snow boots will keep your feet warm!"<<endl;
            }
            break;
        case 'r':
            cout<<"Rain boots will be the best desicion!"<<endl;
            break;
        case 'c':
            cout<<"You can put on boots you want!"<<endl;
            break;
        case 'w':
            cout<<"You are recommended to put sturdy shoes!"<<endl;
            break;
        default:
            break;
        }

    }else{
        cout<<"You have enetered incorrect weather condition!"<<endl;
    }
}