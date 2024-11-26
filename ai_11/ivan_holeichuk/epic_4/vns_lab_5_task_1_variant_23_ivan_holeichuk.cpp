#include <iostream>
#include <vector>

using namespace std;



void fill_2d_array(const vector<int>& arr, vector<vector<int>>& matrix) {

    int n = arr.size();

    for (int j = 0; j < n; j++) {

        int sum = 0, num = 1; 

        for (int i = 0; i < n; i++) {

            while (sum + num > arr[j]) num++; 

            matrix[i][j] = num;

            sum += num;

            num++;
        }
    }
}


void print_matrix(const vector<vector<int>>& matrix) {

    for (const auto& row : matrix) {

        for (int elem : row) {

            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {

    int n;

    cout << "¬вед≥ть розм≥р масиву (N): ";

    cin >> n;

    vector<int> arr(n);

    cout << "¬вед≥ть елементи масиву: ";

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    fill_2d_array(arr, matrix);

    cout << "—формований двовим≥рний масив: " << endl;

    print_matrix(matrix);




    return 0;
}
