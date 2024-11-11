#include <iostream>

using namespace std;

int main() {
    unsigned int l, w, u, d;
    cin>>l>>w>>u>>d;
    if(l>w) {
        cout<<"Forget about the cocktails, man!";
    } else if (l>u+d) {
        cout<<"Forget about the cocktails, man!";
    }else {
        cout<<"Three times Sex on the Beach, please!";
    }
    return 0;
}