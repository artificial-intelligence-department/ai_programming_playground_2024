#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;


bool proste(int pr) {
    if (pr < 2){
        return false;}
    for (int i = 2; i <= pr-1; ++i) {
        if (pr % i == 0){
            return false;}}
    return true;}


void prost(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int A = va_arg(args, int);
        int B = va_arg(args, int);
        cout << "[" << A << ", " << B << "]: ";
        bool found = false;
        for (int num = A; num <= B; ++num) {
            if (proste(num)) {
                cout << num << " ";
                found = true;}}
        cout << endl << endl;}
    va_end(args);}
int main() {
    prost(3, 3, 7, 11, 19, 27, 43);    
    prost(5, 1, 8, 11, 15, 16, 21, 26, 33, 34, 57); 
    prost(6, 16, 20, 33, 37, 55, 62, 65, 78, 90, 100, 101, 123); 
    return 0;}
