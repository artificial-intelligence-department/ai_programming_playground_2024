#include <iostream> 
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib> 
#include <ctime>   
#include <sstream>

using namespace std;

double calculateAverage(const vector<int>& sequence) {
    int sum = 0;
    for (int num : sequence) {
        sum += num;
    }
    return static_cast<double>(sum) / sequence.size();
}

void writeToFile(const string& filename, const vector<int>& sequence, double average) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Generated Sequence: ";
        for (int num : sequence) {
            outFile << num << " ";
        }
        outFile << "\nAverage: " << average << endl;
        outFile.close();
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    vector<vector<int>> sequences(3, vector<int>(10)); 
    vector<double> averages(3); 

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            sequences[i][j] = rand() % 10 + 1;
        }
        averages[i] = calculateAverage(sequences[i]); 
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Sequence " << i + 1 << ": ";
        for (int num : sequences[i]) {
            cout << num << " ";
        }
        cout << "\nAverage: " << averages[i] << endl;
    }

    for (int i = 0; i < 3; ++i) {
        ostringstream filenameStream;
        filenameStream << "sequence_" << i + 1 << ".txt";
        string filename = filenameStream.str();
        writeToFile(filename, sequences[i], averages[i]);
    }

    return 0;
}
