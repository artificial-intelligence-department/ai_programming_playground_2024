#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Temporary{
    int tmp_max;
    int tmp_min;
    vector<int> temp;
};

struct Info{
    int max_val;
    int min_val;
    int m;
    Temporary temp;
};

int main(){
    Info info;
    int n;
    cin >> n;
    if(n < 1) return 0;

    vector<int> r(n);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }

    info.max_val = *max_element(r.begin(), r.end());
    info.min_val = *min_element(r.begin(), r.end());
    info.m = info.max_val - info.min_val;

    for (int i = 0; i < n; ++i) {
        info.temp.tmp_max = info.max_val; 
        info.temp.tmp_min = info.min_val;

        if (r[i] == info.max_val || r[i] == info.min_val) {
            info.temp.temp = r;
            info.temp.temp.erase(info.temp.temp.begin() + i);
            info.temp.tmp_max = *max_element(info.temp.temp.begin(), info.temp.temp.end());
            info.temp.tmp_min = *min_element(info.temp.temp.begin(), info.temp.temp.end());
        }

        if((info.temp.tmp_max - info.temp.tmp_min) < info.m) 
            info.m = info.temp.tmp_max - info.temp.tmp_min;
    }

    cout << info.m << endl;

    return 0;
}