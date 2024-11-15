#include <stdio.h>
#include <iostream>

using namespace std;

int main () {

int m;
int n;

cout << "Enter the value for m:" << endl;
cin >> m;

cout << "Enter the value for n:" << endl;
cin >> n;

// 1) n+++m
int result1 = n+++m;

// 2) m-->n
bool result2 = m-->n;

// 3) n-->m
bool result3 = n-->m;

cout << "first operation result: " << result1 << endl;
cout << "second operation result: " << result2 << endl;
cout << "third operation result: " << result3 << endl;

return 0;
}