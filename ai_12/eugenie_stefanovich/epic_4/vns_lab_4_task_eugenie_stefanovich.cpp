#include<iostream>
using namespace std;



int main() {

    int cher[3];
    int k = 0;
   
    for(int i = 0; i<3; i++ ){
        cin >> k;
        cher[i] = k;
    }

    for (int i = 0; i < 3; i++) 
        cout << cher[i] << " ";
    cout << endl;

    for(int l=0; l < 3; l++){
        for (int i = 0; i < 2; i++) 
            cher[i] = cher[i + 1];
        
        cin >> k;
        cher[2] = k;

        for (int i = 0; i < 3; i++) 
            cout << cher[i] << " ";
        cout << endl;

    }

   return 0;
}
