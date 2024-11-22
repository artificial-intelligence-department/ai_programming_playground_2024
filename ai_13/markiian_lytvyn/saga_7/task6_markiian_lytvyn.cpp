#include <iostream>
using namespace std;
int main(){
    int lviv, kyiv, donetsk, kharkiv;
    cin >> lviv >> kyiv >> donetsk >> kharkiv;
    if (lviv < 0 || kyiv < 0 || kharkiv < 0|| donetsk < 0 || lviv > 1000 || kyiv > 1000 || kharkiv > 1000 || donetsk > 1000){
        cout << "Помилка";
    }
    int souvenir = lviv + kyiv + donetsk + kharkiv;
    cout << souvenir;
}