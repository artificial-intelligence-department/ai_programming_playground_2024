#include <iostream>
#include <cmath>

bool isPalindrom(std::string line, int start, int end){
    if(start < end){
        if(line[start] == line[end]){
            return isPalindrom(line, ++start, --end);
        } else {
            return false;
        }
    }
    return true;
}
bool isPalindrom(int number){
    int num = number, count = 0, a, b;
    while(num>0){
        num/=10;
        count++;
    }
    num=number;
    if(count > 0){
        a = num/(pow(10, count-1));
        b = num%10;
        if(a == b){
            num = (num%(static_cast<int>(pow(10, count-1))))%10;
            return isPalindrom(num);
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    int number = 123404321;
    std::string line = "reerd" ;
    std::cout << "Чи число є паліндромом : " << isPalindrom(number) << "\n";
    std::cout << "Чи слово є паліндромом : " << isPalindrom(line, 0, (line.size()-1));
}