#include <stdio.h>
#include <iostream>

using namespace std;
int main () {
int banknotesNum = 0;
int n = 0;

while (!((n >= 1) && (n <= 1000000000))) {
cin >> n;
}

if (n >= 500){
banknotesNum += n/500;
n = n % 500;
}
if (n >= 200){
banknotesNum += n/200;
n = n % 200;
}
if (n >= 100){
banknotesNum += n/100;
n = n % 100;
}
if (n >= 50){
banknotesNum += n/50;
n = n % 50;
}
if (n >= 20){
banknotesNum += n/20;
n = n % 20;
}
if (n >= 10){
banknotesNum += n/10;
n = n % 10;
}
if (n >= 5){
banknotesNum += n/5;
n = n % 5;
}
if (n >= 2){
banknotesNum += n/2;
n = n % 2;
}
if (n >= 1){
banknotesNum += n/1;
n = n % 1;
}

cout << banknotesNum;


}