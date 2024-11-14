#include <iostream>
#include <vector>  
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {

    const int size = 10; 
    int Numbers[size];  

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i) {
        Numbers[i] = rand() % 100; 
    }

    cout << "Array of random numbers \n";
    for (int i = 0; i < size; ++i) {
        cout << Numbers[i] << " ";
    }
    cout << endl;

    vector<int> Numbers_2; 
    for (int i = 0; i < size; ++i) {
        if (Numbers[i] % 7 != 0) { 
            Numbers_2.push_back(Numbers[i]);
        }
    }

    vector<int> Numbers_3;
    for (int num : Numbers_2) {
        Numbers_3.push_back(num); 
        if (num % 2 != 0) { 
            Numbers_3.push_back(0); 
        }
    }

    cout << "Final array :\n";
    for (int num : Numbers_3) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}