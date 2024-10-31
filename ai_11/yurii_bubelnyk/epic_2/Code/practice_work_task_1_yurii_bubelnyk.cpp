#include <iostream>
using namespace std;

int main()
{

    int weatherCondition;
    cout << "Enter the weather condition" << endl
         << "Possible weather options:" << endl
         << "\t1) sunny;" << endl
         << "\t2) rainy;" << endl
         << "\t3) cloudy;" << endl
         << "\t4) snowy;" << endl
         << "\t5) windy;" << endl;

    bool correctEnter = false;
    while (!correctEnter)
    {
        cin >> weatherCondition;
        switch (weatherCondition)
        {
        case 1:
            cout << "So: A great day for a picnic!" << endl;
            correctEnter = true;
            break;
        case 2:
            cout << "So: Perfect weather to read a book inside!" << endl;
            correctEnter = true;
            break;
        case 3:
            cout << "So: Maybe visit a museum?" << endl;
            correctEnter = true;
            break;
        case 4:
            cout << "So: How about making a snowman" << endl;
            correctEnter = true;
            break;
        case 5:
            cout << "So: Fly a kite if you've got one!" << endl;
            correctEnter = true;
            break;
        default:
            cout << "Choose weather conditions from the list!!!" << endl;
            break;
        }
    }

    cout << "\nAs for the jacket: " << endl;

    if (weatherCondition == 2 || weatherCondition == 4){
        cout << "You should take a jacket" << endl;
    }else{
        cout << "I think you don't need a jacket" << endl;
    }


    cout << "\nAs for the shoes: " << endl;

    if(weatherCondition == 1){
        cout << "Put on your favorite sneakers!" << endl;
    }else if(weatherCondition == 2){
        cout << "Rain boots are a good idea!" << endl;
    }else if(weatherCondition == 3){
        cout << "Any shoe is fine today." << endl;
    }else if(weatherCondition == 4){
        cout << "Snow boots will keep your feet warm!" << endl;
    }else{
        cout << "Put on something sturdy!" << endl;
    }   

    return 0;
}