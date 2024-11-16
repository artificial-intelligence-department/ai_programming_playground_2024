//https://algotester.com/uk/ArchiveProblem/DisplayWithFile/6

#include <iostream>



int main(){


int n;
std::cout << "n = ";
std::cin >> n;

int counter;
while(n >= 500){
    n -= 500;
    counter += 1;
}

while(n >= 200){
    n -= 200;
    counter += 1;
}

if(n >= 100){
    n -= 100;
    counter += 1;

}

if(n >= 50){
    n -= 50;
    counter += 1;
}

while(n >= 20){
    n -= 20;
    counter += 1;
}

if(n >= 10){
    n -= 10;
    counter += 1;
}
if(n >= 5){
    n -= 5;
    counter += 1;
}
while(n >= 2){
    n -= 2;
    counter += 1;
}
if(n == 1){
    n -= 1;
    counter += 1;
}

std::cout << "Counter = " << counter;
    return 0;
}