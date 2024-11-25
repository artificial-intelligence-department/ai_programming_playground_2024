#include <iostream>
using namespace std;

int main(){
    long long h[4], d[4];
    for (int i = 0; i < 4; i++){
        cin >> h[i];}
    bool error = false;
    for (int i = 0; i < 4; i++){
        cin >> d[i];
        if (h[i] < d[i])
            error = true;}
    if (!error){
        bool answer = true;
        for (int i = 0; i < 4; i++){
            h[i] = h[i] - d[i];
            long long d_max = h[0], d_min = h[0];
            for (int j = 1; j < 4; j++){
                if (h[j] < d_min){
                    d_min = h[j];}
                if (h[j] > d_max){
                    d_max = h[j];}}
            if (d_max >= 2 * d_min) {
            answer = false;
            break;}}
        if (answer){
            cout << "YES";}
        else {
            cout << "NO";}}
    else {
            cout << "ERROR";}
    return 0;}