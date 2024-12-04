#include <iostream>
#include <cstdint>
using namespace std;
void intToBitArray(uint64_t num, int bits[64]) {
    for (int i = 0; i < 64; i++) {
        bits[i] = (num >> i) & 1; 
    }
}

uint64_t bitArrayToInt(int bits[64]) {
    uint64_t num = 0;
    for (int i = 0; i < 64; i++) {
        num |= (uint64_t(bits[i]) << i); // shift each bit to its position and add to result
    }
    return num;
}

int main(){
    uint64_t a;
    int N, r, r_f, c_f, c_s, c, temp, b, field[64] = {0};
    cin >> a >> N;
    intToBitArray(a, field); // convert int to binary array

    for(int i = 0; i < N; i++){
        cin >> r >> c;  // input row and column

        r_f = (r-1)*8; //index of first element in a needed row
        c_f = (c-1);  //index of first element in a needed column
        c_s = 8; //column step

        for(int i_r = r_f; i_r < r_f + 8; i_r++){
            field[i_r] = !field[i_r];
        } // change to opposite all elements in a row

        for(int i_c = c_f; i_c <= c_f + c_s*7; i_c += c_s){
            field[i_c] = !field[i_c];
        } 
        field[(r-1)*8 + (c-1)] = !field[(r-1)*8 + (c-1)]; //change again the element at the intersection
    }
    cout << bitArrayToInt(field);
    return 0;
}