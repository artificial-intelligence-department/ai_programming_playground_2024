#include <iostream>

using namespace std;

int main()
{
    double sd, su, v;
    cin >> sd >> su >> v;

    double td = sd/(2.0*v);
    double tu = (2.0*su)/v;

    if(td < tu) cout << "Down";
    else if(td == tu) cout << "Never mind";
    else cout << "Up"; 
}