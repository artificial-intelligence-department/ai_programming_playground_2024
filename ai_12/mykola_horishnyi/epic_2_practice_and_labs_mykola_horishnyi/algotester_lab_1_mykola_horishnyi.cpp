#include <iostream>
using namespace std;

int main() {
    long long H, M;
    cout << "Enter H ,M :";
    cin >> H >> M;
    long long h[3], m[3]; 

    for (int i = 0; i < 3; ++i)
    {
        cin >> h[i] >> m[i];
    }

    bool win = true;
   
    for (int i = 0; i < 3; ++i)
    {
        if (H - h[i] > 0) 
        {
            H -= h[i];
        }      
        else if (M - m[i] > 0) 
        {
            M -= m[i];
        }
        else 
        {
            win = false;
            break;
        }
    }

    cout << (win ? "YES" : "NO") << endl;


    return 0;
}











