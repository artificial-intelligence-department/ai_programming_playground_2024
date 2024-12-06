#include <iostream>
#include <vector>
using namespace std;

int main() {
    int siz = 5; 
    vector<double> seq; 
    double sum = 0.0; 
    for (int i = 0; i < siz; i++) {
        double el;
        cin >> el; 
        seq.push_back(el);
        sum += el;
        double aver = sum / (i + 1); 
        cout << "Середнє арифметичне: " << aver << endl; 
    }

    return 0;
}
