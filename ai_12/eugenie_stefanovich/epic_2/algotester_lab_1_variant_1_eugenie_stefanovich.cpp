#include <iostream>
using namespace std;

int main() {
    int man , hp , uman , uhp;
    cin >> man;
    cin >> hp;
    for(int i = 0; i < 3; i++){
        uhp = 0;
        uman = 0;
        cin >> uman;
        cin >> uhp;
        man -= uman;
        hp -= uhp;
        if(uhp >0 && uman>0){
            cout<<"NO";
            exit(0) ;
        }
        

    }

    if(hp>0 &&man>0)
        cout << "YES";
    else
        cout<<"NO";

    return 0;

}
    
