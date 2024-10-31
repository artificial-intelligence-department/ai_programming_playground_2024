#include <iostream>
using namespace std;
int main (){
   int n,m, one;
    cout << "n:" << endl;
    cin >> n;
    cout << "m:"<< endl;
    cin >> m;
one= --m-++n;
cout << " --m-++n="<< one << endl;
if (m*n < n++ ){
    cout<< "m*n<n++ : true" << endl;
} else {cout<< "m*n<n++ : false" << endl;}
if (n-- > m++) {
    cout << "n-- > m++: true" <<endl;
} else {    cout << "n-- > m++: false" <<endl;
}
}