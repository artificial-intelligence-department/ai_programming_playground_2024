#include <iostream>
#include <vector>
using namespace std;

int main(){
    const double mi = 1609.344;
    const double mi_us = 1609.347;
    int distance;
    cin>>distance;
    int bonus = 0;
    int discount = 0;
    bool get_bonus = false;
    string s;
    double a;
    string distance_s = to_string(distance);
    vector <int> id = {'m', 'a', 'r', 't', 'a'};
    for(int i = 0; i< distance_s.size(); i++){
        int k = 0;
        while(k<=distance_s.size()){
            get_bonus = false;
            if(distance_s[i] == distance_s[distance_s.size() - k]){
                get_bonus = true;
            }
            k++;
        }
        
    }
    cout<<"Convert?(mi/mi_us/m)"<<endl;
    cin>>s;
    if( s == "mi"){
        a == mi;
    }
    else if (s == "mi_us"){
        a == mi_us;
    }
    else if (s == "m"){
        a == 1;
    }
    if(get_bonus == true){
        bonus+=200;
        distance+=bonus;
    }
    while(distance>= 100){
        discount+=1;
        distance-=100;
    }
    cout<<"USER ID:";
    for(int i = 0; i< 5; i++){
        for(int j = 0; j< 5 - i ; j++){
            if( id[i] > id[i+j]){
                swap (id[i], id[i+j]);
            }
        }
    }
    for(int i : id){
        cout<<i * 0.4;
    }
    cout<<endl;
    cout<<"DISTANCE:"<<distance * 1000 * a <<endl;
    cout<<"BONUS:"<<bonus * 1000 * a<<endl;
    cout<<"DISCOUNT:"<<discount<<endl;
     

}