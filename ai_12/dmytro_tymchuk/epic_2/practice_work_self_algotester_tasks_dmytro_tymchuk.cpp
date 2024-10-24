///«Камінь-ножиці-папір»(1691)

#include<iostream>
using namespace std;

int main()
{
    int rm,sm,pm,rz,sz,pz;

    cin>>rm>>sm>>pm;
    cin>>rz>>sz>>pz;

    int s=0;
    if (rm > sz) s += sz ;
    else s += rm;

    if (sm > pz) s += pz ;
    else s += sm;

    if (pm > rz) s += rz ;
    else s += pm;

    cout << s << endl;
    return 0;
}