#include <iostream>  
#include <string>    

using namespace std; 

int main() {
    int k;             
    cin >> k;          
    string s;        
    cin >> s;         

    string pattern = "TOILET"; 
    int count = 0;            
    size_t pos = 0;        

    
    while ((pos = s.find(pattern, pos)) != string::npos) {
        count++;      
        pos += pattern.size(); 
    }

    
    if (count >= k) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;  
    }

    return 0; 
}
