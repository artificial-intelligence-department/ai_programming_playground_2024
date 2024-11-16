#include <iostream>
using namespace std;

int main() {
    long H; long M;
    long sumH; long sumM;
    long resH; long resM;
   long move1[2]; long move2[2]; long move3[2];
    cin>>H >>M;
    if (H<=0||M<=0){return 0;}
    else
    cin>>move1[0]>>move1[1];
    cin>>move2[0]>>move2[1];
    cin>>move3[0]>>move3[1];
    if (move1[0]<0||move1[1]<0||move2[0]<0||move2[1]<0||move3[0]<0||move3[1]<0){
        return 0;
    }
    else
    if((move1[0]>0&&move1[1]>0)||(move2[0]>0&&move2[1]>0)||(move3[0]>0&&move3[1]>0)){
        cout<<"NO";
        return 0;}
    else
        sumH=move1[0]+move2[0]+move3[0];
        resH=H-sumH;
        sumM=move1[1]+move2[1]+move3[1];
        resM=M-sumM;
            if(resM>0&&resH>0)
                cout<<"YES";
            else cout<<"NO";

    return 0;}