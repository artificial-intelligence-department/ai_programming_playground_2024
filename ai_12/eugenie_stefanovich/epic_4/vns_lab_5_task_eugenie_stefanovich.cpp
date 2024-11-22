#include <iostream>
using namespace std;


int main(){
  
     int N = 3 , wid , inf = 2147483647;
     
     int mat[3][3];

    for(int i =0; i < N ; i++){
        for(int l = 0; l < N; l++){
            cin >> wid;
            mat[i][l] = wid;
        }
    }

    cout << endl;

    for(int i =0; i < N ; i++){
        for(int l = 0; l < N; l++){  
           cout <<  mat[i][l] << " ";
        }
        cout << endl;
    }
    int lmin;
    int aks = -inf;

    for(int i = N - 1; i> -1; i--){
        lmin = inf;
        for(int l = 0; l < N; l++){
            if(mat[l][i]> aks && mat[l][i] < lmin)
                lmin = mat[l][i];
        }
        if(lmin > aks && lmin != inf){
            aks = lmin;
            cout << aks << endl;
        }
        else{
            cout << "Не можна";
            exit(0);
        } 
    }

    cout << "Можна";

    return 0;
}

