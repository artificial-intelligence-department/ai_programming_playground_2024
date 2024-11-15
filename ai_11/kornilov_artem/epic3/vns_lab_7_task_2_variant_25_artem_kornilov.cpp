#include <iostream>
#include <vector>

using namespace std;


void deleteEvenRows(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 1) {
            matrix[i].clear();  
        }
    }
}


void deleteBetweenZeros(vector<int>& arr) {
    int firstZero = -1, secondZero = -1;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;
            } else {
                secondZero = i;
            }
             
        }

        if (firstZero != -1 && secondZero != -1) {
            arr.erase(arr.begin() + firstZero + 1, arr.begin() + secondZero);
        }

    }
    
   
   
}

void print (vector<vector<int>> vec2d) {
    for (const auto& row : vec2d) {
        if (!row.empty()) { 
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
} 

void print (vector<int> vec1d) {
    for (int val : vec1d) {
        cout << val << " ";
    }
}

int main() {
    
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    
    cout << "Original 2-dimensional arr: " << endl;
    print(matrix);

    deleteEvenRows(matrix);

    cout << "\nWith lines deleted:" << endl;
    print(matrix);
 
    vector<int> arr = {1, 2, 0, 3, 4, 0, 5, 6};
    
    cout << "\nOriginal arr: ";
    print(arr);
    cout << endl;
    
    deleteBetweenZeros(arr);
    
    cout << "After deleting elements between two 0's: ";
    print(arr);
    cout << endl;

    return 0;
}
