#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string ruad;
    cin >> ruad;
    int s_k = 0, s_v = 0, g_k = 0, g_v = 0;
    for(int i = 0; i < n; i++)
    {
        if(ruad[i] == 'V') s_v++;
        else s_k++;

        if(s_k >= 11 && s_k - s_v >= 2){
            g_k++;
            s_v = 0;
            s_k = 0;
        }
        if(s_v >= 11 && s_v - s_k >= 2){
            g_v++;
            s_k = 0;
            s_v = 0;  
        }
    }
    cout << g_k << ":" << g_v << endl;
    if(s_v != 0 || s_k != 0){
        cout << s_k << ":" << s_v << endl;
    }
    return 0;
}
