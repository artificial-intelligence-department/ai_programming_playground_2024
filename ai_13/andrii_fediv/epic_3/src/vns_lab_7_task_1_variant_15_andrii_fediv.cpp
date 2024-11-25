#include <iostream>
#include <vector>
using namespace std;


vector<int> oct2dec(vector<int> arr){
    return arr;
};
template <typename T, typename... Args>
vector<int> oct2dec(vector<int> arr, T t, Args... args){
        int octal = t;
        int dec = 0;
        int s = 1;
        
        while (octal) {
            int ld = octal % 10;//остання цифра
            octal /= 10;
            dec += ld * s;//типу степінь
            s *= 8;
        }
    arr.push_back(dec);
    return oct2dec(arr, args...);
}

void output(vector<int> arr){
    for(int el: arr)
        cout << "\t" << el;
    cout << "\n\n";
}


int main(){
    vector<int> a1, a2, a3;
    output(oct2dec(a1, 1234, 3456, 235));
    output(oct2dec(a2, 65, 465, 467, 8765, 124, 45));
    output(oct2dec(a3, 6565, 34353, 2122, 666, 111, 2454, 1));
    return 0;
}