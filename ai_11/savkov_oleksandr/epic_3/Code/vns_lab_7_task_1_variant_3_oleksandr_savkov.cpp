#include <iostream>
#include <cstdarg>
#include <vector>

using namespace std;

void sum(int kilkistNumbers, ...) {
    va_list firstPar;
    va_start(firstPar, kilkistNumbers);
    int summaZagal = 0;
    
    vector<int> listNumbers;

    for (int i = 0; i < kilkistNumbers; i++) {
        int nowNum = va_arg(firstPar, int);
        listNumbers.push_back(nowNum);
        // cout << listNumbers[i] << endl;
    }

    va_end(firstPar);


    for (int i = 0; i < listNumbers.size(); i+=2) {
       if (i + 1 >= listNumbers.size()) {
            summaZagal += listNumbers[i] * 1;
        } else {
            summaZagal += listNumbers[i] * listNumbers[i + 1];
        }
    }

    cout << "Сума: " << summaZagal << endl;
   
}

int main() {
    sum(5, 7, 1, 8, 3, 5);
    sum(10, 4,6,8,2,5,6,7,1,0,6);
    sum(12, 3, 0, 2, 5, 3, 6 ,7, 8, 4, 7, 4, 3); 
    return 0;
}
