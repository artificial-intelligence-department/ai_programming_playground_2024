#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n_notebook, n_pencil, value_nb, value_p;
    cout << "Вартість зошита: ";
    cin >> value_nb;
    cout << "Вартість олівця: ";
    cin >> value_p;
    cout << "К-сть зошитів: ";
    cin >> n_notebook;
    cout << "К-сть олівців: ";
    cin >> n_pencil;
    cout << "Вартість покупки = " << (n_notebook * value_nb + n_pencil * value_p) << " грн" << endl;
}