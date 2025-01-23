#include <iostream>
using namespace std;
const string VARIANT = "C187";
int main (){
    int a, b;
    cin >> a >> b;
    int n = b-a;
    int *result = new int[n]{0};
    int indx = 0;
    int neparni_counter = 0, parni_counter = 0;
    for (int i = a; i < b; i++){
        neparni_counter = 0; 
        parni_counter = 0;
        int k = i;
        while(k>0){
            
            if ((k%10)%2 !=0){
                neparni_counter++;
            }
            else{
                parni_counter++;
            }
            
            k = k/10;
            }
        if(parni_counter < neparni_counter){
                result[indx++] = i;
            }
        }
        bool aa= false;
        for(int i = 0; i < n; i++){
            if (result[i] !=0){
            aa =true;
            }
        }
        if (a){
            for(int i = 0; i < n; i++){
                cout << result[i];
             } 
             return 0;
        } 

         cout << "none";
        
    return 0;
}