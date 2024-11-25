#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int k;              
    string s;             
    
    cin >> k;
    cin >> s;
    
    string target = "TOILET";
    int targetLength = target.length();
    int n = s.length();
    
    int count = 0;       
    int i = 0;            
    
    while (i <= n - targetLength) 
    {
        if (s.substr(i, targetLength) == target) 
        {
            count++;       
            if (count >= k) 
            {
                cout << "YES" << endl; 
                return 0;
            }
            i += targetLength; 
        } else 
        {
            i++; 
        }
    }
    
    cout << "NO" << endl;  
    return 0;
}
