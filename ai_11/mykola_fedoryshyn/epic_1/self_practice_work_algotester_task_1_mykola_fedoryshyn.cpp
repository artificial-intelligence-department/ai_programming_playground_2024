#include <iostream>
#include <string.h>
using namespace std;

main (){
    string day;
    int nday, num;

    cin >> day;
    cin >> num;
    
    if (day == "Monday"){
        nday = 0;
    }
    if (day == "Tuesday"){
        nday = 1;
    }
    if (day == "Wednesday"){
        nday = 2;
    }
    if (day == "Thursday"){
        nday = 3;
    }
    if (day == "Friday"){
        nday = 4;
    }
    if (day == "Saturday"){
        nday = 5;
    }
    {
        nday = 6;
    }
    
    int list[7] = {0,0,0,0,0,0,0};
    for (num; num>0; num--){
        list[nday] += 1;
        nday += 1;
        if (nday == 7){
            nday = 0;
        }
    }

    for (int i = 0; i < 7; i++){
        cout << list[i] << " ";
    }
    return 0;
}
//C:/GitHub/ai_programming_playground_2024/ai_11/mykola_fedoryshyn/epic_1/