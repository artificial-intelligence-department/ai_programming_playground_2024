#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int findMaxRepeatedElement(const vector<vector<int>>& arr) {
    unordered_map<int, int> frequencyMap; 
    int maxRepeated = -1; 

    for (const auto& row : arr) {
        for (int num : row) {
            frequencyMap[num]++;
        }
    }

//pair.second - частота , pair.first - значення

    for (const auto& pair : frequencyMap) {
        if (pair.second > 1) { 
            if (pair.first > maxRepeated) {
                maxRepeated = pair.first; 
            }
        }
    }
    return maxRepeated; 
}

int main() {

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cin.ignore();

    vector<vector<int>> array(rows, vector<int>(cols));

    cout << "Enter the elements of the array :" << endl;
    for (int i = 0; i < rows; i++) {
        string line;
        cout << "Row " << i + 1 << ": ";
        getline(cin, line); 

        istringstream iss(line); 
        for (int j = 0; j < cols; j++) {
            if (!(iss >> array[i][j])) { 
                cout << "Invalid input. Please enter " << cols << " integers." << endl;
                return 1; 
            }
        }
    }

    int maxRepeated = findMaxRepeatedElement(array);

    if (maxRepeated != -1) {
        cout << "Maximum of repeating elements : " << maxRepeated << endl;
    } else {
        cout << "There are no duplicate elements. " << endl;
    }

    return 0;
}