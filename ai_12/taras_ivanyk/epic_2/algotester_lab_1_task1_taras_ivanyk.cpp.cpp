#include <iostream>
using namespace std;

int main()
{
    long long H,M;
    cin >> H >> M;

    bool lose = false;

    for(int i = 0; i < 3; ++i)
    {
        long long hi,mi;
        cin >> hi >> mi;

        if (hi > 0 && mi > 0){
        lose = true;
        }

        H -= hi;
        M -= mi;

        if (H <= 0 || M <= 0){
        lose = true;
        }
    }
    
    if(!lose){
    cout << "YES";
    }
    else{
    cout << "NO";
    }


    return 0;
}