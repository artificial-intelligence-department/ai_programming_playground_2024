#include <bits/stdc++.h>
using namespace std;
string convert(int num){
    int temp, temp1, temp2;
    string result;
    do{
        result.insert(result.begin(), (num % 3 + '0'));
        num /= 3;
    }while(num > 0);
    return result;
}
void func(int count, ...){
    int temp;
    vector <char> res;
    va_list args;
    va_start (args, cout);
    for (int i = 0; i < count; i++){
        temp = va_arg(args, int);
        cout << "Число " << temp << " в трійковй системі числення = "<< convert(temp) << endl;
    }
    va_end(args);
}

int main(){
    func(3, 34, 54, 21);
    func(4, 34, 54, 21, 81);
    func(7, 34, 54, 21, 21, 22, 32, 92);
    return 0;
}