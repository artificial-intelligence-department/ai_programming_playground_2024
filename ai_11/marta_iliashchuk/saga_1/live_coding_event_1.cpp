#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void function_1(double a, double b, double c,double d, double e, double f, int const variant){
    vector <double> k;
    k.push_back(a);
    k.push_back(b);
    k.push_back(c);
    k.push_back(d);
    k.push_back(e);
    k.push_back(f);

    double values[3];
    sort(k.begin(), k.end());

    values[0] = (k[4]);
    values[1] = (k[5]);
    values[2] = (k[6]);

    remove(k.begin(), k.end(), k[k.size()]);
    k.pop_back();

    remove(k.begin(), k.end(), k[k.size()]);
    k.pop_back();

    remove(k.begin(), k.end(), k[k.size()]);
    k.pop_back();
    double sum2;
    for (int i = 0; i<3; i ++){
        cout<<"Smallest: "<<k[i]<<endl;
        sum2 += k[i];
    }
    double sum1;
    cout<<endl;
    for (int i = 0; i<3; i ++){
        cout<<"Biggest: "<<values[i]<<endl;
        sum1 += values[i];
    }
    cout<<endl;

    if(sum1>sum2*2){
        cout<<sum1*sum2/variant;
    }
    if(sum1>sum2*3){
        cout<<sum1/sum2/variant;
    }
    if(sum1>sum2*4){
        cout<<(sum1+sum2)/variant;
    }
    
}

int main(){
int const variant = 10;
double a, b,c,d,e,f;
cin>>a>>b>>c>>d>>e>>f;
function_1(a,b,c,d,e,f, variant);
}