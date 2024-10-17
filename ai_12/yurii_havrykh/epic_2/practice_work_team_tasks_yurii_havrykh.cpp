#include<bits/stdc++.h>
using namespace std;

int main(){
    string weather;
    int numCase;
    cout<<"Weather: ";
    cin>>weather;
    while((weather!="sunny")&&(weather!="rainy")&&(weather!="cloudy")&&(weather!="snowy")&&(weather!="windy")){
        cout<<"Wrong input, try again"<<endl;
        cout<<"Weather: ";
        cin>>weather;
    }
    if ((weather=="rainy")||(weather=="snowy")){
        cout<<"You should wear a jacket"<<endl;
    }
    else{
        cout<<"You don't need to wear a jacket"<<endl;
    }
    if (weather=="sunny"){
        cout<<"A great day for a picnic!"<<endl;
        numCase=0;
    }
    else if(weather=="rainy"){
        cout<<"Perfect weather to read a book inside!"<<endl;
        numCase=1;
    }
    else if(weather=="cloudy"){
        cout<<"Maybe visit a museum?"<<endl;
        numCase=2;
    }
    else if(weather=="snowy"){
        cout<<"How about making a snowman?"<<endl;
        numCase=3;
    }
    else{
        cout<<"Fly a kite if you have one!"<<endl;
        numCase=4;
    }

    switch(numCase){
        case 0:
            cout << "Wear your favorite shoes!" << endl;
            break;
        case 1:
            cout<<"Rainboots are a great idea."<<endl;
            break;
        case 2:
            cout << "Today, any shoe is suitable."<<endl;
            break;
        case 3:
            cout << "Snow boots will keep your feet warm!"<<endl;
            break;
        case 4:
            cout << "Wear something sturdy!"<<endl;
            break;
    }
}