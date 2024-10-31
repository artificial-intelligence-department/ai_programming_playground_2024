#include <iostream>
using namespace std;

int main(){
    long long Hit, Mana, hit1, mana1, hit2, mana2, hit3, mana3, hit4, mana4;
    cin >> Hit >> Mana;
    cin >> hit1 >> mana1;
    cin >> hit2 >> mana2;
    cin >> hit3 >> mana3;
    hit4=hit1+hit2+hit3;
    mana4=mana1+mana2+mana3;
    if ((hit1 > 0 && mana1 > 0) || (hit2 > 0 && mana2 > 0) || (hit3 > 0 && mana3 > 0)){
        cout << "NO";}
    else if (Hit-hit4 > 0 && Mana-mana4 > 0){
        cout << "YES";}
    else{
        cout << "NO";}}