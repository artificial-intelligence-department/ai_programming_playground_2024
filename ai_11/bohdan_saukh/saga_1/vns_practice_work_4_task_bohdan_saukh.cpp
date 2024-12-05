#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    const int numSequences = 3;
    const int sequenceLength = 10;

    int sequences[numSequences][sequenceLength];
    double averages[numSequences] = {0.0};

    for (int i = 0; i < numSequences; i++) {
        cout << "Послідовність " << i + 1 << ": ";
        for (int j = 0; j < sequenceLength; j++) {
            sequences[i][j] = rand() % 10 + 1;
            cout << sequences[i][j] << " ";
        }
            
        double sum = 0;
        for (int j = 0; j < sequenceLength; j++) {
            sum += sequences[i][j];
        }
        averages[i] = sum / sequenceLength;
        cout << endl << "Середнє арифметичне: " << averages[i] << endl << endl;
    }

    return 0;
}