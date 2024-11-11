#include <iostream>

using namespace std;

int main(){

    float n, m;
    cout << "Enter variable n ";
    cin >> n;
    cout << "Enter variable m ";
    cin >> m;
    cout << (n+++m)<<"\n";
    if ((m-- >n) == 1){
        cout <<"True"<<"\n";
    }
    else{
        cout <<"False"<<"\n";
        }
    if ((n-- >m) == 1){
        cout <<"True"<<"\n";
    }
    else{
        cout <<"False"<<"\n";
        }
    return 0;
}
