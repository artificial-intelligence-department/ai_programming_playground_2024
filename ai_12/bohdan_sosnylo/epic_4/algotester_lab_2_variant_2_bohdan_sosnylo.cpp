#include <iostream>

using namespace std;

int main(){

int N;
cin >> N;
int r[N];
for (int i = 0; i<N;i++){
    cin >> r[i];
}
int a,b,c;
cin >> a >> b >> c;

int r1[N];
int r2[N];
int k = 0, m = 0;
for(int i = 0; i<N;i++){
    if(r[i] != a && r[i] != b && r[i] != c){
        r1[k] = r[i];
        ++k;
    }
} 
for(int i = 1;i<k;i++){
    r2[m] = r1[i]+r1[i-1];
    ++m;

}
cout << m <<endl;
for(int i = 0;i<m;i++){
    cout << r2[i] <<" ";
}
   
   
    return 0;
}
