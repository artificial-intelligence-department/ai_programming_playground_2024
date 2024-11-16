#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

long long factorial(int num){
    if(num>0){
        return num*factorial(num-1);
    }
    else 
        return 1;
}

int main(){
    int n=10;
    double sum1=0;
    double sum2=1;
    float e=0.0001;
    double difference=10;

    for (double x=0.1; x<=1; x+=((1-0.1)/10)){
        cout<<"X = "<<x<<setw(8)<<"\t";
        for (int i=0; i<=n; ++i){
        sum1+=pow(-1,i)*(pow(x, 2*i)/(factorial(2*i)));
        }
        cout<<"SN = "<<sum1<<"\t";
        sum1=0;
        
            int i=1;
            while(difference>e){
                sum2+=pow(-1,i)*(pow(x, 2*i)/(factorial(2*i)));
                difference=fabs(cos(x)-sum2);
                i++;
                }
            cout<<"SE = "<<sum2<<"\t";
            sum2=1;
            difference=10;

            cout<<"Y = "<<cos(x)<<endl;
        }
    

    return 0;}