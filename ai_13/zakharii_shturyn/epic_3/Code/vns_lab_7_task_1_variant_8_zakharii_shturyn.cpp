// 8 variant
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int func(unsigned int n_args, int arg, ...)
// {
//     vector<int> arr(n_args);
//     for(unsigned int i = 0; i < n_args; ++i)
//         arr[i] =  *((int*)&arg + i);
//     int min = *min_element(arr.begin(), arr.end());
//     return min;
// }

int min(int a, int b, int c, int d, int e) {
    vector<int> arr = {a,b,c,d,e};
    int min = *min_element(arr.begin(), arr.end());
    return min;
}
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    vector<int> arr = {a,b,c,d,e,f,g,h,i,j};
    int min = *min_element(arr.begin(), arr.end());
    return min;
}
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    vector<int> arr = {a,b,c,d,e,f,g,h,i,j,k,l};
    int min = *min_element(arr.begin(), arr.end());
    return min;
}

int main() {

    cout << min(1,5,9,-1,6) << endl;
    cout << min(22,6,43,11,9,15,73,-22,-59,0) << endl;
    cout << min(6,9,18,22,-45,-5,-1,-17,8,90,23,-11) << endl;
    // cout << func(12, 6,9,18,22,-45,-5,-1,-17,8,90,23,-11);


    return 0;
}