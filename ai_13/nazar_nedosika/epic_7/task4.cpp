#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int sum = 0;  
    const int count = 10; 

    cout << "Згенеровані числа: ";

    for (int i = 0; i < count; ++i) {
        int random_number = rand() % 10 + 1; 
        cout << random_number << " ";
        sum += random_number; 
    }

    double average = static_cast<double>(sum) / count;

    cout << "\nСереднє арифметичне: " << average << endl;

    return 0;
}