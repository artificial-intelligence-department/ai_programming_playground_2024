#include <iostream>

using namespace std;

int whw(int god, int hw){
    return(god*60 + hw);
}

int wgod(int hw){
    cout << hw/60 <<" - годин\n";
    cout << hw%60  <<" - хвилин\n";
}

int main(){

    int god ,hw , c;
    cin >> god;
    cin >> hw;
    c =  whw(god , hw);
    cout  << "перша функція\n" << whw(god , hw) << endl;

    cout << "\nдруга фунцкія\n" << wgod(c) ;
  
    return 0;
}