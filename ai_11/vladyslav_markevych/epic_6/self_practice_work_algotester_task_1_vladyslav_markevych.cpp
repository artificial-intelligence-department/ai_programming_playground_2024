#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a,b;

    cin>>a >>b;

    int maxim, minimum;
    maxim = max(a,b);
    minimum = min(a,b);

    if(maxim - minimum > 1){
        cout<<minimum + 1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}