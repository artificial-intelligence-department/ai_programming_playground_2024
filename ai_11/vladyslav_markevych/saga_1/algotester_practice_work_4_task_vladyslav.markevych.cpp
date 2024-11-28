#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    int result = 0;
    int totaldist = 0;
    for(int i = 0; i<n; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        long long distance = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

        totaldist += distance;
    }
    cout<<totaldist;
    return 0;
}